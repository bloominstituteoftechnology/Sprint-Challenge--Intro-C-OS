#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *pDirent;
  DIR *pDir;

  // Parse command line

  if (argc < 2)
  {
    printf("Sample Usage: ./lsls <dirname>\n");
    pDir = opendir(".");
    while ((pDirent = readdir(pDir)) != NULL)
    {
      printf("[%s]\n", pDirent->d_name);
    }
    closedir(pDir);
    return 0;
  }
  
  
  // Open directory

  pDir = opendir(argv[1]);


  if (pDir == NULL)
  {
    printf("Cannot open directory '%s'\n", argv[1]);
    exit(1);
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