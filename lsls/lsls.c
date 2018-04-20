#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *dp;
  if (argc == 0 || argc > 2) {
    printf("Use by typing in: lsls <dirname>\n");
    return 1;
  }
  if (argc == 1) {
    dir = opendir(".");
  } else {
    dir = opendir(argv[1]);
  }

  if (dir == NULL) {
    printf("Cannot open directory %s\n", argv[1]);
    exit(1);
  }

  while((dp  = readdir(dir)) != NULL) {
    printf("[%s]\n", dp->d_name);
  }
  closedir(dir);
  return 0;
}
