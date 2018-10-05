#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  printf("argc: %d\n", argc);
  // Parse command line
  for (int i = 0; i < argc; i++) {
    printf("path: %s\n", argv[i]);
    // Open directory
    if (DIR *opendir(char *argv[i]) == NULL) {
      fprintf(stderr, "Open directory failed\n");
      exit(1);
    }
  }
  // Repeatly read and print entries

  // Close directory

  return 0;
}