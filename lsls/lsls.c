#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
  int main(int argc, char **argv)
{
  // Parse command line
  DIR *dir;
  struct dirent *pDirent;

  if (argc < 2)
  {
    printf("Usage: print <dirname>\n");
  }

  // Open directory
  /*The opendir() function opens a directory stream corresponding to the directory name, 
  and returns a pointer to the directory stream. 
  The stream is positioned at the first entry in the directory.*/

 if (argv[1] == NULL)
  {
    dir = opendir(".");
  }
  else
  {
    dir = opendir(argv[1]);
  }

  if (dir == NULL)
  {
    printf("Cannot open directory %s\n", argv[1]);
    return 1;
  }

  // Repeatly read and print entries
  while ((pDirent = readdir(dir)) != NULL)
  {
    printf("%s\n", pDirent->d_name);
  }

  // Close directory
  closedir(dir);
  return 0;
}

