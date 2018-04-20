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

  struct dirent *entry;
  char *currentDir = ".";

  // Repeatly read and print entries
  if ((dir = opendir(currentDir)) == NULL)
  {
    perror("There was an error opening this directory");
  } else {
  // Close directory
  while ((entry = readdir(dir)) != NULL)
  {
    printf(" %s\n", entry-> d_name);
  }
  closedir(dir);
  }

  return 0;
}