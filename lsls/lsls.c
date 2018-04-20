#include <stdio.h>
#include <dirent.h>
#include <errno.h>

void printDirs(DIR *d)
{
  struct dirent *entry;
  entry = readdir(d);
  while(entry != NULL) {
    printf("%s\n", entry->d_name);
    entry = readdir(d);
  }
  closedir(d);
}

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  if(argc > 2) {
    // printf("%d\n%s\n%s", argc, argv[0], argv[1]);
    perror("Too many arguments supplied");
    return 1;
  }
  if(argc > 1) {
    DIR *d = opendir(argv[1]);
    if(d == NULL) {
      perror("Directory doesnt exist");
    } else {
      printDirs(d);
    }
  } else {
    DIR *d = opendir(".");
    if(d == NULL) {
      perror("Directory doesnt exist");
    } else {
      printDirs(d);
    }
  }

  return 0;
}