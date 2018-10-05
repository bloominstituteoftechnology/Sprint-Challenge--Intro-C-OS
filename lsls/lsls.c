#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *path;

  printf("argc: %d\n", argc);
  // Parse command line
  for (int i = 0; i < argc; i++) {
    printf("path: %s\n", argv[i]);
    // Open directory
    if ((dir = opendir(*argv[i])) == NULL) {
      fprintf(stderr, "Open directory failed\n");
      exit(1);
    } else {
      // Repeatly read and print entries
      while ((path = readdir(dir)) != NULL) {
        printf("%s\n", path->d_name);
      }
    }
  }
  // Close directory
  closedir(dir);

  return 0;
}