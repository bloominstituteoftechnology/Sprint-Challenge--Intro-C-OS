#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory
  struct dirent *dir;
  DIR *d = opendir(".");
  // Repeatly read and print entries
  if (d) {
    while((dir = readdir(d)) != NULL) {
      printf("%s\n", dir->d_name);
    }
  }
  // Close directory
  closedir(d);

  return 0;
}