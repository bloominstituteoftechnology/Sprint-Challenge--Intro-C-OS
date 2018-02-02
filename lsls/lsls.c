#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char *argv[])
{
  DIR *dir;
  struct dirent *sd;
  // Parse command line
  if (argc < 2) {
    argv[argc++] = ".";
  }

  // Open directory
  dir = opendir(argv[1]);

  if(dir == NULL) {
    printf("Error! Unable to open directory. \n");
    exit(1);
  }


  // Repeatly read and print entries
  while( (sd=readdir(dir)) != NULL ) {
    printf(">> %s\n", sd->d_name);
  }

  // Close directory

  closedir(dir);

  return 0;

}