#include <stdio.h>
#include <dirent.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char target_dir[] = ".";
  // Open directory
  DIR *dirp;
  struct dirent *dp;

  if ((dirp = opendir(target_dir)) == NULL) {
        perror("couldn't open that dir!");
        return 0;
    }

  // Repeatly read and print entries
  do {
    if ((dp = readdir(dirp)) != NULL) {
      (void) printf("%s\n", dp->d_name);
    }
  } while (dp != NULL);
  // Close directory
  closedir(dirp);
  return 0;
}