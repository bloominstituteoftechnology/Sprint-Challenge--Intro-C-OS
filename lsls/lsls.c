#include <stdio.h>
#include <dirent.h>
#include <libgen.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory
  DIR *dir;
  struct dirent *dp;

  // Repeatly read and print entries
if ((dir = opendir(".")) == NULL ) {
  perror("Cannot open .");
  // exit(0);
}

while ((dp = readdir (dir)) != NULL) {
  printf("%s \n", dp->d_name);
}

  // Close directory

  return 0;
}