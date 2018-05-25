#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *d;
  char *currDir;
  struct dirent *dirEntry;
  // Parse command line - first get user dir
  if (argc > 1) {
    currDir = argv[1];
  } else {
    currDir = ".";
  }

  // Open directory

  d = opendir(currDir);

  if (d == NULL)
  {
    printf("Nothing exists here. Your directory doesn't.");
    exit(1);
}

  // Repeatly read and print entries

  while ((dirEntry = readdir(d)) != NULL) {
    printf("%s\n", dirEntry->d_name);
  }

  // Close directory
  closedir(d);
  return 0;
}