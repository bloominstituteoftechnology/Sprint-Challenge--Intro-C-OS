#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  {
    int count;
    for (count = 0; count < argc; count++)
      puts(argv[count]);
  }

  // Open directory
  DIR *directory;
  struct dirent *entry;

  directory = opendir(".");
  if (directory == NULL)
  {
    printf("Error: Unable to read the contents of the directory. Exiting process.");
    exit(1);
  }

  // Repeatly read and print entries
  while ((entry = readdir(directory)) != '\0')
  {
    printf("%s ", entry->d_name);
  }
  printf("\n");
  // Close directory
  closedir(directory);

  return 0;
}