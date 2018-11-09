#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  if(argc <= 2){
  // Open directory
    DIR *d;    
    if(argv[1]){
      d = opendir(argv[1]);
    } else {
      d = opendir(".");
    }
    struct dirent *dir;
  // Repeatly read and print entries
    if(d == NULL) {
      fprintf(stderr, "That folder does not exist!\n");
      exit(1);
    }else {
      while ((dir = readdir(d)) != NULL) {
        printf("%s\n", dir->d_name);
      }
    }
    
  // Close directory
    closedir(d);
  }else {
    fprintf(stderr, "Too many parameters, please only enter 1 filepath\n");
    exit(1);
  }
  return 0;
}