#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>

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
    exit(1);
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