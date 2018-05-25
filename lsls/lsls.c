#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{

  // Parse command line
  int d;
  char *args;

  if (argc == 1)
  {
    args = '.';
  }
  else if (argc == 2)
  {
    args = argv[1];
  }
  else
  {
    fprintf(stderr, "usage: lsls [args]\n");
    exit(1);
  }

  // Open directory
  DIR *directory = opendir(args);
  // Repeatly read and print entries
  struct dirent *ent;
  if (directory == NULL)
  {
    fprintf(stderr, "lsls: cannot open directory%s\n", args);
    exit(2);
  }
  while ((ent = readdir(directory)) != NULL)
  {
    printf("%s\n", ent->d_name);
  }

  // Close directory
  closedir(directory);
  return 0;
}