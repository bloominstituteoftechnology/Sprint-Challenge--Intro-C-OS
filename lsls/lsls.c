#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  struct dirent *directoryEntry;
  DIR *directory;
  char defaultDir[2] = ".";

  // Open directory
  directory = argc < 2 ? opendir(defaultDir) : opendir(argv[1]);
  if (directory == NULL)
  {
    printf("Could not open %s\n", argv[1]);
    return 1;
  }

  // read directory entry
  while ((directoryEntry = readdir(directory)) != NULL)
  {
    printf("directory: %s\n", directoryEntry->d_name);
  }

  closedir(directory);

  return 0;
}