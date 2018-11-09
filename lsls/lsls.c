#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  DIR *directory;

  struct dirent *ent;

  // Open directory
  directory = opendir(".");

  if (argc > 1)
  {
    directory = opendir(argv[1]);
  }

  else if (directory == NULL)
  {
    printf("No directory could be found\n");
  }

  else
  {
    // Repeatly read and print entries
    while ((ent = readdir(directory)) != NULL)
    {
      printf("  %s\n", ent->d_name);
    }
  }

  // Close directory
  closedir(directory);

  return 0;
}