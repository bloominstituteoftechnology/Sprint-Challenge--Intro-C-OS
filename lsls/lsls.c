#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line and Open directory

  DIR *directory; // initialize a pointer for the directory that's DIR type

  if (argc == 2) {
    directory = opendir(argv[1]);
  } else {
    printf("Please enter: './lsls <directory_name>'\n");
    exit(1);
  }

  if (directory == NULL) {
    fprintf(stderr, "This directory doesn't exist.\n");
    exit(1);
  };

  // Repeatly read and print entries

  // Print file size in bytes

  struct dirent *dir; // initialize a struct for the dir that's dirent type
  struct stat bytes; // initialize a struct for the bytes that's stat type

  while ((dir = readdir(directory))) {
    stat(dir->d_name, &bytes);
    
    // Mark Directories

    if (S_ISDIR(bytes.st_mode)) {
      printf("%s %s\n", "<DIR>", dir->d_name);
    } else {
      printf("%lld %s\n", bytes.st_size, dir->d_name);
    }
  };

  // Close directory

  closedir(directory);

  return 0;
}