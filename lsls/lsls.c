#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char *argv[])
{
  // Parse command line

  if(argc > 2) {
    puts("Please use command like so: ./lsls <directory name>");
    return 0;
  }

  
  // Open directory
  DIR *dir;
  dir = opendir(argv[1]);
  // Repeatly read and print entries
  struct dirent *ent;

  if (dir) {
    while((ent = readdir(dir)) != NULL) {
      printf("%s\n", ent->d_name);
    }
  // Close directory
    closedir(dir);
  }
  return 0;
}