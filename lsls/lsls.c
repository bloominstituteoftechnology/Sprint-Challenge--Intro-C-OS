#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *path[50];
  if (argc == 1) {
		*path = ".";
	} else {
    *path = argv[1];
  }
  // Open directory
  DIR *d = opendir(*path);
  // Checks for errors
  if (d == NULL) {
    printf("\033[31merror\033[37m: no such file or directory\n");
    return 0;
  }
  // Repeatly read and print entries
  struct dirent *id;
  while ((id = readdir(d)) != NULL) {
    printf("%s\n", id->d_name);
  }
  // Close directory
  closedir(d);
  return 0;
}