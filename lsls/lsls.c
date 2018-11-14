#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory
  DIR *pdir;
  struct dirent *pent = NULL;

  // if (argc > 2) {
  //   printf("\nERROR!");
  //   exit(1);
  // } else if (argc == 1) {
  //   pdir = ".";
  // } else {
  //   pdir = argv[1];
  // }
    if(argc>1)
  {
      pdir=opendir(argv[1]);
  } else {
      pdir=opendir(".");
  }

  pdir = opendir (".");
  if (pdir == NULL)
  {
      printf ("\nERROR! pdir could not be initialised correctly");
      exit (1);
  }

  // Repeatly read and print entries
  while ((pent = readdir (pdir))!=NULL)
  {
      if (pent == NULL)
      {
          printf ("ERROR! pent could not be initialised correctly");
          exit (3);
      }
      printf ("%s\n", pent->d_name);
  }

  // Close directory
  closedir (pdir);

  return 0;
}