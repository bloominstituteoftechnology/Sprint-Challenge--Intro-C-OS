#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *entry;
  char *currentDir = ".";
  // Parse command line

  // Open directory

  // Repeatly read and print entries
  if ((dir = opendir(currentDir)) == NULL)
  {
    perror("opendir error");
  }
  else
  {
    while ((entry = readdir(dir)) != NULL)
    {
      printf(" %s\n", entry->d_name);
    }
    closedir(dir);
  }

  // Close directory

  return 0;
}