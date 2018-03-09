#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
	DIR *directory;
  // Parse command line
  if (argc == 2) {
	  directory = argc[1];
	}
	else {
		printf("Usage: <directory>/n args - name of directory to lookup";

  // Open directory

  opendir(directory)
   if (d == NULL)
  {
    printf("Error: Could not read directory\n");
    exit(ENOENT);
  }
  // Repeatly read and print entries
  struct dirent *currentDir = readdir(directory);

  while(currentDir != NULL)
  {
    printf("%s\n", currentDir->dir_name);
    currentDir = readdir(directory);
  }
   // Close directory
  closedir(directory);

  return 0;
}
  return 0;
}
