#include <stdio.h>
#include <dirent.h>
#include <errno.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  struct dirent *entry;
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
      entry = readdir(d);
      while(entry != NULL) {
        printf("%s\n", entry->d_name);
        entry = readdir(d);
      }
      closedir(d);
    }
  } else {
    DIR *d = opendir(".");
    if(d == NULL) {
      perror("Directory doesnt exist");
    } else {
      entry = readdir(d);
      while(entry != NULL) {
        printf("%s\n", entry->d_name);
        entry = readdir(d);
      }
      closedir(d);
    }
  }

  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}