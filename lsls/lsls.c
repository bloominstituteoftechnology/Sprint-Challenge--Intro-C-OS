#include <stdio.h>
#include <dirent.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dirp;
  struct dirent *dp;
  char target_dir[1024] = ".";

  if (argc > 2) {
    printf("The number of args from the command line is: %i", argc);
    perror("Don't provide multiple arguments!");
    return 0;
  };
  
  if (argc == 2) {
    sprintf(target_dir, argv[1]);
  };

  if ((dirp = opendir(target_dir)) == NULL) {
        perror("couldn't open that dir!");
        return 0;
    }

  do {
    if ((dp = readdir(dirp)) != NULL) {
      (void) printf("%s\n", dp->d_name);
    }
  } while (dp != NULL);

  closedir(dirp);
  return 0;
}