#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <inttypes.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *dir;
  struct stat buf;
  // Parse command line
  if(argc <= 2){
  // Open directory
    DIR *d;    
    if(argv[1]){
      d = opendir(argv[1]);
    } else {
      d = opendir(".");
    }
  // Repeatly read and print entries
    if(d == NULL) {
      fprintf(stderr, "That folder does not exist!\n");
      exit(1);
    }else {
      while ((dir = readdir(d)) != NULL) {
        stat(dir->d_name, &buf);
        if(S_ISDIR(buf.st_mode) != 0) {
          printf("%9s  %s\n", "<DIR>", dir->d_name);
        } else{
          printf("%9ld  %s\n", buf.st_size, dir->d_name);
        }
        
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