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
  printf("argc number is %i", argc);
  if (argc < 2) {
    printf("Usage: lsls <dirname>\n");
    return 1;
  }

  dir = opendir(argv[1]);
  if (dir == NULL) {
    printf("Cannot open directory %s\n", argv[1]);
    exit(1);
  }

  while((dp  = readdir(dir)) != NULL) {
    printf("[%s]\n", dp->d_name);
  }
  closedir(dir);
  return 0;

  // Parse command line

  // Open directory

  // Repeatly read and print entries

  // Close directory
}



  // if ((dir = opendir (".")) == NULL) {
  //   perror ("Cannot open.");
  //   exit (1);
  // }
  // for (int i = 1; i < argc; i++) {
  //   do {
  //     errno = 0;
  //     if ((dp = readdir(dir)) != NULL) {
  //       if (stsrcmp(dp->d_name, argv) != 0) { 
  //         continue; 
  //       }

  //     printf("[%s]\n", argv);
  //     closedir(dir);
  //     return;
  //   }
  //   } while (dp != NULL);

  //   if (errno != 0) {
  //     perror("error reading directory");
  //   } else {
  //     printf("failed to find %s\n", argv);
  //     closedir(dir);
  //   }
  //   return;
  // }