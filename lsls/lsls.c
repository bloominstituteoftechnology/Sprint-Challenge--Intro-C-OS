#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  char defaultDir[2] = ".";
  struct dirent *dirEntry;
  DIR *dirName;

  // Open directory
  dirName = argc < 2 ? opendir(defaultDir) : opendir(argv[1]);
  if (dirName == NULL) {
    printf("Failed to open directory");
    return 1;
  }

  // Repeatly read and print entries
  while ((dirEntry = readdir(dirName)) != NULL){
    printf("%s\n", dirEntry->d_name);
  }
  // Close directory
  closedir(dirName);
  return 0;
}