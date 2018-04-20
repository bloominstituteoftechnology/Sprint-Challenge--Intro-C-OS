#include <dirent.h>
#include <errno.h>
#include <stdio.h>

/**
 * Main
 */
int main(int argc, char **argv) {

  DIR *dir;
  struct dirent *entry;
  dir = opendir(argv[1]);
  if (dir != NULL) {
    while ((entry = readdir(dir)) != NULL) {
      printf("  %s\n", entry->d_name);
    }
    closedir(dir);
  }
  else {
    perror("opendir() error");
  }

  // Parse command line

  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}