#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  // Open directory
  // Repeatly read and print entries
  // Close directory
  DIR *dir;
  struct dirent *dp;

  if ((dir = opendir(".")) == NULL) {
    perror("Cannot open .");
    return 0;
  }

  do {
    if ((dp = readdir(dir)) != NULL) {
      (void) printf("%s\n", dp->d_name);
    }
  } while((dp = readdir(dir)) != NULL);

  closedir(dir);

  return 0;
}
