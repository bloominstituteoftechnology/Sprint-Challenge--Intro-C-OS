#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  DIR *pDir;
  struct dirent *pDirent;

  // Open directory
  pDir = opendir(".");
  if (pDir == NULL)
  {
    printf("Cannot open directory %s\n", argv[1]);
    return 1;
  }

  // Repeatly read and print entries
  while ((pDirent = readdir(pDir)) != NULL)
  {
    printf("[%s]\n", pDirent->d_name);
  }

  // Close directory
  closedir(pDir);
  return 0;
}