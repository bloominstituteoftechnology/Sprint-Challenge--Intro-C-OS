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

  DIR *pDir = opendir (argv[1]);
  struct dirent *pDirent;

  // Repeatly read and print entries
  if (argc < 2) {
    pDir = opendir(".");
  }
  if (pDir == NULL){
    printf("invalid directory: %s\n", argv[1]);
    return 1;
  }

  while ((pDirent = readdir(pDir)) != NULL) {
            printf ("[%s]\n", pDirent->d_name);
        }

  // Close directory
  closedir (pDir);

  return 0;
}