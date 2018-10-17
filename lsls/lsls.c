#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  DIR *directory;
  char *current;

  if (argc == 1) {
    current = ".";
  } else {
    current = argv[1];
  }

  // Open directory
  if ((directory = opendir(current)) == NULL) {
    printf("Directory is empty!");
    exit(0);
  } else {
    // Repeatly read and print entries
    struct dirent *entry;
    while ((entry = readdir(directory)) != NULL) {
      printf("%s\n", entry->d_name);
    }
    // Close directory
    closedir(directory);
  }

  return 0;
}