#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
    char *path;
    if (argc == 1) {
    path = ".";
    } else if (argc == 2) {
      path = argv[1];
    } else {
      printf("Enter valid directory path\n");
      exit(1);
    }
  // Open directory
    DIR *dir = opendir(path);
  // Repeatly read and print entries
    struct dirent *ent;
    if (dir == NULL) {
      printf("Can't open directory\n");
      exit(1);
    }
    while ((ent = readdir(dir)) != NULL) {
      printf("%s\n", ent->d_name);
    }
  // Close directory
    closedir(dir);
    return 0;
}