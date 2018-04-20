#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  printf("Directory: ");

  for(int i = 1; i < argc; i++) {
    printf("%s\n", argv[i]);
  }

  // Open directory
  DIR *d = opendir(argv[1] ? argv[1] : ".");
  struct dirent *dir;

  if (errno != 0) {
    printf("Error: %s\n", strerror(errno));
    exit(errno);
  } else if (d) {
    // Repeatly read and print entries
    while ((dir = readdir(d)) != NULL) {
      printf("%s\n", dir->d_name);
    }
    // Close directory
    closedir(d);
  }
  return 0;
}