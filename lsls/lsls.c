#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  DIR *dir;
  struct dirent *dp;
  char *currentDir;

  if (argc > 1) {
    currentDir = argv[1];
  } else {
    currentDir = ".";
  };
  // Open directory

  if ((dir = opendir(currentDir)) == NULL)
  {
    printf("Couldn't open %s\n", argv[1]);
    exit(1);
  }
  // Repeatly read and print entries
  while ((dp = readdir(dir)) != NULL)
  {
    printf("%s\n", dp->d_name);
  }
  // Close dir
  closedir(dir);
  return 0;
}