#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *dir_arg;
  if (argc > 1) {
    dir_arg = argv[1];
  } else {
    dir_arg = ".";
  }

  // Open directory
  DIR *dir;
  struct dirent *dp;
  char *file_name;
  dir = opendir(dir_arg);
  if (dir == NULL) {
    printf("There was an error reading that directory\n");
    return 0;
  }

  // Repeatly read and print entries
  while((dp=readdir(dir)) != NULL) {
      file_name = dp->d_name;
      printf("| %s\n", file_name);
  }
  // Close directory
  closedir(dir);
  return 0;
}
