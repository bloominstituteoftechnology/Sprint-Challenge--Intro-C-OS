#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir; 
  struct dirent *sd; 

  
  // Parse command line

  // Open directory
  dir = opendir(".");
  if(dir == NULL)
  {
    printf("Error! Unable to open directory.\n");
    exit(1); 
  }
  readdir(dir);
  // Repeatly read and print entries
  while ( (sd=readdir(dir)) != NULL)
  {
    printf(">> %s\n", sd->d_name);
  }
  // Close directory
  closedir(dir); 

  return 0;
}