#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *p;
  if (argc == 1)
  {
    p = ".";
  }
  if (argc == 2)
  {
    p = argv[1];
  }

  DIR *pDir;
  pDir = opendir(p);
  if (pDir == NULL)
  {
    printf("Cannot open directory.\n");
    return 1;
  }
  // Repeatly read and print entries
  struct dirent *pDirent;
  while ((pDirent = readdir(pDir)) != NULL)
  {
    printf("%s\n", pDirent->d_name);
  }
  // Close directory
  closedir(pDir);
  return 0;
}