#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory

  // Repeatly read and print entries

  // Close directory

  DIR *d;

  if (argc < 2)
  {
    d = opendir(".");
  }
  else 
  {
    d = opendir(argv[1]);
  }

  if (d == NULL)
  {
    printf("Error: Could not read directory\n");
    exit(ENOENT);
  }

  struct dirent *currentDir = readdir(d);

  while(currentDir != NULL)
  {
    printf("%s\n", currentDir->d_name);
    currentDir = readdir(d);
  }
  closedir(d);

  return 0;
}