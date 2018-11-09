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
    path = ".";
  }
  if (argc == 2)
  {
    path = argv[1];
  }
  
  // Open directory
  DIR *d = opendir(path);
  if (d == NULL)
  {
    printf("FAIL to open directory\n");
    return 1;
  }
  
  // Repeatly read and print entries
  struct dirent *dDirent;
  while ((dDirent = readdir(d)) != NULL)
  {
    printf("%s\n", dDirent->d_name);
  }

  // Close directory
  closedir(d);

  return 0;
}