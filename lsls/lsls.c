#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory
  DIR *dir;
  struct dirent *sd;

  dir = opendir(".");
  // handle error if null
  if (dir == NULL)
  {
    printf("Error! Cannot open directory");
    exit(1);
  }
  // Repeatly read and print entries

  while ( (sd = readdir(dir)) != NULL)
  {
    printf("%s\n", sd->d_name);
  }
  // Close directory
  closedir(dir);
  return 0;
}