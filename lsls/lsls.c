#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *directory;

  if (!(directory = argv[1])) {                           // combined assign and check if argv exists
    directory = ".";                                      // if none supplied, default to current directory
  };

  // Open directory
  DIR *ls_directory = opendir(directory);

  if (ls_directory == NULL) {                             // validate directory name
    printf("Directory does not exist: %s\n", argv[1]);
    exit(1);                                              // close files and exit due to invalid directory name
  };

  // Repeatly read and print entries
  struct dirent *entry;
  
  while ((entry = readdir(ls_directory)) != NULL) {       // combined assign and check entry for null
    printf("%s\n", entry->d_name);
  };

  // Close directory
  closedir(ls_directory);                                 // close normally after end of directory reached

  return 0;
};