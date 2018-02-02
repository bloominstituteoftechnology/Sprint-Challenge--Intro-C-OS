#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *pDirent;
  DIR *pDir;
  char x[2] = ".";

  if (argc < 2) {
    pDir = opendir (x);
  }
  else {
    pDir = opendir (argv[1]);
      if (pDir == NULL) {
        printf ("Cannot open directory '%s'\n", argv[1]);
        return 1;
    }
  }

  while ((pDirent = readdir(pDir)) != NULL) {
    printf ("%s\n", pDirent->d_name);
  }

  closedir (pDir);
      
  return 0;
}