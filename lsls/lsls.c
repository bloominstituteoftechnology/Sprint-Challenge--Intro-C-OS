#include <stdio.h>
#include <dirent.h>
#include <stdlib.h> /* included for exit() use requested in specs */

int main(int argc, char **argv)
{ 
  if (argc > 2) {
    printf("Too many arguments supplied by the user. Please try again.\n");
    exit(-1);
  }
  DIR *directory = opendir(argv[1] ? argv[1] : ".");
  if (directory) {
    struct dirent *next = readdir(directory);
    while ((next = readdir(directory)) != NULL) {
      printf("%s\n", next->d_name);
    }
  } else {
    printf("An error occured while reading the data. Please try again.\n");
    exit(-1);
  }
  closedir(directory);
  return 0;
}