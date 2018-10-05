#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{

  DIR *directory;
  struct dirent *dir;
  directory = opendir(".");
  if (directory)
  {
    while ((dir = readdir(directory)) != NULL)
    {
      printf("%s\n", dir->d_name);
    }
    closedir(directory);
  }
  return (0);
  // Parse command line

  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}