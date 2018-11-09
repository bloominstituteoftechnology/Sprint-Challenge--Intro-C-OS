#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  DIR *directory;
  struct dirent *entry;
  char *currentDirectory = ".";

  // Open directory
  if ((directory = opendir(currentDirectory)) == NULL) {
    perror("The Directory can not be opened.");
  }

  // Repeatly read and print entries
  else {
    while ((entry = readdir(directory)) != NULL) {
      printf("%s\n", entry->d_name);
    }
  // Close directory
    closedir(directory);
  }
  
  return 0;
}