#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  // assuming current director initially
  char *directory;

  if (argv[1]) {
    directory = argv[1];
  } else {
    directory = ".";
  }

  // Open directory
  DIR *ls_directory = opendir(directory);

  if (ls_directory == NULL) {
    printf("Directory does not exist: %s\n", argv[1]);
    exit(1);
  // } else {
  //   printf("Directory opened: %s\n", directory);
  };

  // Repeatly read and print entries
  struct dirent *entry;
  entry = readdir(ls_directory);
  
  while (entry != NULL) {
    printf("%s\n", entry->d_name);
    entry = readdir(ls_directory);
  };

  // Close directory
  closedir(ls_directory);

  return 0;
}