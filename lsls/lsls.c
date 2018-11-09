#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *path;
  if (argc == 1)
  {
    // If no arguments print set path as current directory
    path = ".";
  }
  else
  {
    // Set path as argument
    path = argv[1];
  }

  // Open directory
  DIR *directory = opendir(path);
  if (directory == NULL)
  {
    printf("no such file or directory: %s\n", path);
    return 0;
  }

  // Repeatly read and print entries
  struct dirent *entry;
  while ((entry = readdir(directory)) != NULL)
  {
    printf("%s\n", entry->d_name);
  }
  // Close directory
  closedir(directory);
  return 0;
}
