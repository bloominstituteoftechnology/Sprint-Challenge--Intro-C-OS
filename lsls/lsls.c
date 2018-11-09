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
  char *file_name;

  if(argc != 2){
    fprintf(stderr, "Usage: ./lsls <PATH>\n");
    exit(1);
  }

  dir = opendir(argv[1]);

  while((dp=readdir(dir)) != NULL){
    printf("%s\n", dp->d_name);
  }

  closedir(dir);
  return 0;
}
