#include <stdio.h>

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  DIR *dir;
  struct dirent *sd;
  
  dir = opendir(".");
  if (dir == NULL){
    printf("Error! Unable to open directory. \n");
    exit(1);
  }
  
  if ((sd = readdir(dir) == NULL))
  {
    printf("sd is null");
  } else {
    printf("sd isn't null");
  }

  // while((sd = readdir(dir)) != NULL)
  // {
  //   printf(">> %s\n", sd->d_name);
  // }

  // Close directory
  closedir(dir);
  return 0;
}