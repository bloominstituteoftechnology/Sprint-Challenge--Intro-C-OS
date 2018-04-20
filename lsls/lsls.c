#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dirp;
  struct dirent *dp;
  struct stat buf;
  char target_dir[1024] = ".";

  if (argc > 2) {
    printf("The number of args from the command line is: %i", argc);
    perror("Don't provide multiple arguments!");
    return 0;
  };
  
  if (argc == 2) {
    sprintf(target_dir, "%s", argv[1]);
  };

  if ((dirp = opendir(target_dir)) == NULL) {
        perror("couldn't open that dir!");
        return 0;
    }

  do {
    if ((dp = readdir(dirp)) != NULL) {
      char* path = malloc(1024*sizeof(char));
      sprintf(path, "%s/%s", target_dir, dp->d_name);
      stat(path, &buf);
      free(path);
      if (buf.st_mode & S_IFDIR) {
        printf("%10s %s\n", "<DIR>", dp->d_name);
      } else {
      printf("%10lld %s\n", buf.st_size, dp->d_name);
      }
    }
  } while (dp != NULL);

  closedir(dirp);
  return 0;
}