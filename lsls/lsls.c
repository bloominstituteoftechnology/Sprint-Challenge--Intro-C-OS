#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory
  DIR *d;
  struct dirent *dir;
  d = opendir(".");
  // Repeatly read and print entries
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      printf("%s\n", dir->d_name);
    }
    clodedir(d);
  }
  // Close directory

  return 0;
}