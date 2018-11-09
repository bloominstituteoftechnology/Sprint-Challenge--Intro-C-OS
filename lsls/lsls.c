#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
DIR *d;
struct dirent *dir;
  // Open directory
  //pass in argv duh that's the current dir.
d = opendir(argv[1]);
if(d){
    // Repeatly read and print entries
  while((dir = readdir(d)) != NULL){
    printf("%s\n", dir->d_name);
  }
    // Close directory
  closedir(d);
}
  return 0;
}
