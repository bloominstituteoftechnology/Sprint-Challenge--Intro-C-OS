#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  
  // Open directory
  DIR *dir;
  struct dirent *dp;
  char *file_name;
  dir = opendir(".");
  // Repeatly read and print entries
  while((dp=readdir(dir)) != NULL) {
      file_name = dp->d_name;
      printf("- %s\n", file_name);
  }
  // Close directory
  closedir(dir);
  return 0;
}
