#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *path = argv[1];

  // Open directory
  DIR *directory = opendir(path);

  /* check if directory is NULL */
  if (directory == NULL)
  {
    printf("Directory << %s >> not found.\nError: %s\n", path, strerror(errno));
    exit(1);
  }

  // Repeatly read and print entries
  else
  {
    struct dirent *ent;

    while ((ent = readdir(directory)) != NULL)
    {
      printf("%s\n", ent->d_name);
    }
  }

  // Close directory
  closedir(directory);

  return 0;
}