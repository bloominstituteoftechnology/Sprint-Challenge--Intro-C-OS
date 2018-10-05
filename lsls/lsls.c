#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

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

  // Repeatly read and print entries and Close directory

  struct dirent *dir; // initialize a struct for the dir that's dirent type

  while ((dir = readdir(directory))) {
    printf("%s\n", dir->d_name);
  }

  closedir(directory);

  return 0;
}