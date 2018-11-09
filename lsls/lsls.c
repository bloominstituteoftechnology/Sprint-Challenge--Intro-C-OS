#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  DIR *dir;
  struct dirent *dp;
  char *filename = ".";
  // Open directory
  if ((dir = opendir(filename)) == NULL)
  {
    perror("Can't open this file");
  }
  // Repeatly read and print entries

  // Close directory
  else
  {
    while ((dp = readdir(dir)) != NULL)
    {
      printf(" %s\n", dp->d_name);
    }
    closedir(dir);
  }

  return 0;
}