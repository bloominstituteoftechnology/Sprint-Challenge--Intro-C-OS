#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
   struct dirent *pDirent;
    DIR *pDir;
  // Parse command line
  // Open directory
     pDir = opendir ((argc == 1) ? "." : argv[1]);
    if (pDir == NULL) {
        printf("Can not open this dir '%s'\n", argv[argc]);
        return 1;
    }
  // Repeatly read and print entries
  while ((pDirent = readdir(pDir)) != NULL) {
        printf ("%s\n", pDirent->d_name);
    }
  // Close directory
closedir(pDir);
  return 0;
}