#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *directory;

  if(!(directory = argv[1])) {
    directory = ".";
  }


  // Open directory
  DIR *ls_directory = opendir(directory);

  if(ls_directory == NULL) {
    printf("This directory does not exist: %s\n,", argv[1]);
  };

  // Repeatly read and print entries

  // Close directory

  return 0;
}