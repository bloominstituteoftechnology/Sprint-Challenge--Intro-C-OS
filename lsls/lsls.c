#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *entry;

  if (argc == 1) {
    dir = opendir(".");
  } else {
    while(argv[1][0] == '/') {
      argv[1]++;
    }
    dir = opendir(argv[1]);
  }

  if (dir == NULL) {
    printf("There seems to be an error opening the directory\n");
    exit(0);
  }

  while((entry = readdir(dir)) != NULL) {
    printf("%s\n", entry->d_name);
  }

  closedir(dir);

  return 0;
}