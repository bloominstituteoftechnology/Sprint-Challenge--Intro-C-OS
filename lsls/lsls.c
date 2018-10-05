#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *entry;
  // Open directory
  dir = opendir(".");
  // Parse command line
  if (argc > 1)
  {
    dir = opendir(argv[1]);
  }

  if (dir == NULL)
  {
    printf("Error in opening directory!\n");
  }
  else
  {
    // Repeatly read and print entries
    while ((entry = readdir(dir)) != NULL)
    {
      printf("  %s\n", entry->d_name);
    }
    // Close directory
    closedir(dir);
  }

  return 0;
}