#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  struct dirent *dirEnt;
  DIR *dir;

  // Open directory
  if (argc < 2)
  {
    dir = opendir(".");
    while ((dirEnt = readdir(dir)) != NULL)
    {
      printf("[%s]\n", dirEnt->d_name);
    }
    closedir(dir);
  }


  // Repeatly read and print entries
  dir = opendir(argv[1]);
  

  // Close directory
  if (dir == NULL)
  {
    return 1;
  }
  while ((dirEnt = readdir(dir)) != NULL)
  {
    printf("[%s]\n", dirEnt->d_name);
  }
 
 closedir(dir);
  return 0;
}