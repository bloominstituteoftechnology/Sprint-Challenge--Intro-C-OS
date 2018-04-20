#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *ent;
  // Parse command line
  int d;
  char *args;

  for (d = 0; d < argc; d++)
  {
    // input transformed to args which opens specified dir.
    args = argv[d];
  }
  // Open directory
  DIR *directory = opendir("args");
  // Repeatly read and print entries

  // Close directory
  closedir(directory);
  return 0;
}