#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *dp;
  char * file_name;
  char * directory;

  // Parse command line
  if (argc < 2) {
    directory = ".";
  } else {
    directory = argv[1];
  }

  // Open directory
  dir = opendir(directory);
  if (dir == NULL) {
    printf("Could not open directory\n");
    return 1;
  }
  while ((dp=readdir(dir)) != NULL) {
    file_name = dp->d_name;
    printf("%s\n",file_name);
  }
  // Close directory
  closedir(dir);
  return 0;
}
