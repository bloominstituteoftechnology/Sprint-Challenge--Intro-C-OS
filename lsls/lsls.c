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

  // Open directory: depending on what input was typed in.
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