#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
{
    int count;
    for (count=0; count<argc; count++)
        puts (argv[count]);
}
  // Open directory

  pDir = opendir (v[1]);

  // Repeatly read and print entries
  while ((pDirent = readdir(pDir)) != NULL) {
            printf ("[%s]\n", pDirent->d_name);
        }

  // Close directory
  closedir (pDir);

  return 0;
}