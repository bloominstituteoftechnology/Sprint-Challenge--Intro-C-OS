#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
// #include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  DIR *dir;
  struct dirent *dp;
  // struct stat buf;
  char *path;

  for (int i = 0; i < argc; i++) {
    path = argv[i];

    if (i == 0 && argc == 1) {
      path = ".";
    } else if (i == 0 && argc > 1) {
    } else {

      // Open directory
      dir = opendir(path);

      // Repeatly read and print entries
      if (dir != NULL) {
        printf("Path: < %s >\n", path);

        while ((dp = readdir(dir)) != NULL) {
          printf("%s\n", dp->d_name);
        }
      } else {
        printf("Path: < %s > not found.\n", path);
        exit(1);
      }
    }
  }

  // Close directory
  closedir(dir);

  return 0;
}