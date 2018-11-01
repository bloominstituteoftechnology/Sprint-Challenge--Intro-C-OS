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
    for (count=0; count<argc; count++)
        puts (argv[count]);
}

  // Open directory
  DIR *directory;
  struct dirent *entry;

  directory = opendir(".");

  if (directory == NULL)
  {
    printf("haha nope");
    exit(1);
  }

  // Repeatly read and print entries
  while ( (entry = readdir(directory)) != '\0')
  {
    printf("%s\n", entry->d_name);
  }

  // Close directory
  closedir(directory);

  return 0;
}