#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
// #include <sys/stat.h>

/**
 * Main
 */

int main(int argc, char **argv)
{
  struct dirent *pDirent;
  DIR *pDir;

  //Parse CLI
  if (argc < 2)
  {
    printf("Usage: ./lsls <directory>");
    return 1;
  }

  // Open Dir
  pDir = opendir(argv[1]);
  if (pDir == NULL)
  {
    printf("Cannot open directory '%s'\n", argv[1]);
    return 1;
  }

  // Print and read entriers

  while ((pDirent = readdir(pDir)) != NULL)
  {
    printf("%s\n", pDirent->d_name);
  }

  // Close Dir
  closedir(pDir);
  return 0;
}
