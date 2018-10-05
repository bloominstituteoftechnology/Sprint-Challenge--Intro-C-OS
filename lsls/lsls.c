#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory
  DIR *dir;
  dir = opendir(".");

  if(dir == NULL)
  {
    perror("opendir");
    exit(1);
  }

  // Repeatly read and print entries
  struct dirent *entry;

  while((entry = readdir(dir)) != NULL)
  {
    printf(" %s\n", entry->d_name);
  }

  // Close directory
  if(closedir(dir) == -1)
  {
    perror("closedir");
    exit(1);
  }

  closedir(dir);

  return 0;
}
