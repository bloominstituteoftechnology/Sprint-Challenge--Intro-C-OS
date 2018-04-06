#include <stdio.h>
#include<sys/stat.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
  // Parse command line
  {
  int i;

  printf("There are %d command line argument(s):\n", argc);

  for (i = 0; i < argc; i++) {
    printf("   %s\n", argv[i]);
  }

  DIR *dp;
  struct stat st;

  // Open directory
  dp = opendir(argv[1]);

  char buf[512];

  if (dp == NULL) {
    fprintf(stderr, "Error: can't open directory %s\n", argv[1]);
    exit(1);
  }

  struct dirent *sd;

  // Repeatly read and print entries
  while ((sd = readdir(dp)) != NULL) {
    stat(buf, &st);
    printf("%s\n",sd->d_name);
    // printf("file size is %10lld\n", st.st_size);
    // printf("file size is %d\n", st);
  }
    // Close directory
  closedir(dp);
  return 0;
}