#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  int i;

  printf("There are %d command line argument(s):\n", argc);

  for (i = 0; i < argc; i++)
  {
    printf("   %s\n", argv[i]);
  }

  return 0;

  struct dirent *pDirent;
  DIR *pDir;

  // Open directory
  if ((pDir = opendir("argv")) == NULL)
  {
    printf("Cannot open '%s'\n", argv[i]);
    exit(0);
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