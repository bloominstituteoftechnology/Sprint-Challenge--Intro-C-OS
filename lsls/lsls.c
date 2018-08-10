#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  DIR *dir;
  struct dirent *dp;
  if (argc < 2) {
      if ((dir = opendir (".")) == NULL) {
          perror ("Cannot open .");
          exit (1);
      }
  } else {
    if ((dir = opendir (argv[1])) == NULL) {
          perror ("Cannot open .");
          exit (1);
      }
  }
  // Open directory

  // Repeatly read and print entries
  while ((dp = readdir (dir)) != NULL) {
    printf("%s\n", dp->d_name);
  }
  // Close directory
  closedir(dir);
  return 0;
}