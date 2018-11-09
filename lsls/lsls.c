#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  DIR *dir;
  struct dirent *dp;
  char *filename = ".";
  if (argc == 2)
  {
    filename = argv[1];
  }
  else if (argc > 2)
  {
    fprintf(stderr, "One directory at a time good sir.\n");
  }
  // Open directory
  if ((dir = opendir(filename)) == NULL)
  {
    fprintf(stderr, "Can't do that.");
    exit(1);
  }
  // Repeatly read and print entries
  while ((dp = readdir(dir)) != NULL)
  {
    printf("%s\n", dp->d_name);
  }

  // Close directory
  int closed = closedir(dir);
  if (closed != 0)
  {
    printf("could not close directory");
  }

  else
  {
    closedir(dir);
  }

  return 0;
}