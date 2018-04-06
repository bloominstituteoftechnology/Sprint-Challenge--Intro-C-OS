#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  DIR *dir;
  struct dirent *entry;
  char *currentDir = ".";
  // Open directory
  if((dir = opendir(currentDir)) == NULL)
  {
    perror("Can't Open Directory");
  }
  // Repeatly read and print entries
  else
  {
    while ((entry = readdir(dir)) != NULL)
    {
      printf(" %s\n", entry->d_name);
    }
    // Close directory
    closedir(dir);
  }

  return 0;
}