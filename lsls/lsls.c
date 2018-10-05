#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  char *dirname;
  struct dirent *entry;

  // Parse command line
  if (argc == 1) {
    dirname = ".";
  } else if (argc == 2) {
    dirname = argv[1];
  } else {
    fprintf(stderr, "usage: lsls [dir]\n");
    exit(1);
  }
  // Open directory
  DIR *d = opendir(dirname);
  // Repeatly read and print entries
  if (d == NULL) {
    fprintf(stderr, "lsls: cannot open %s\n", dirname);
    exit(2);
  } else {
    while ((entry = readdir(d)) != NULL) {
      printf("%s\n", entry->d_name);
    }
  }
  // Close directory
  closedir(d);

  return 0;

  // // INCORRECT CODE, FIRST ATTEMPT
  // DIR *dir = ;
  // struct dirent *path;

  // printf("argc: %d\n", argc);
  // // Parse command line
  // for (int i = 0; i < argc; i++) {
  //   printf("path: %s\n", argv[i]);
  //   // Open directory
  //   if ((dir = opendir(*argv[i])) == NULL) {
  //     fprintf(stderr, "Open directory failed\n");
  //     exit(1);
  //   } else {
  //     // Repeatly read and print entries
  //     while ((path = readdir(dir)) != NULL) {
  //       printf("%s\n", path->d_name);
  //     }
  //   }
  // }
  // // Close directory
  // closedir(dir);

  // return 0;
}