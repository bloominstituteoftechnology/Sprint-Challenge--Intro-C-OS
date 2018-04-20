#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{

  // Parse command line
  DIR *dir;
  struct dirent *dent;
  struct stat buffer;
  int exists;

  // Open directory
  if (argc == 1)
  {
    dir = opendir(".");
  }
  else
  {
    while (argv[1][0] == '/')
    {
      argv[1]++;
    }
    dir = opendir(argv[1]);
  }
  if (dir == NULL)
  {
    fprintf(stderr, "Could'nt open \".\"\n");
    exit(1);
  }

  // Repeatly read and print entries
  for (dent = readdir(dir); dent != NULL; dent = readdir(dir))
  {
    exists = stat(dent->d_name, &buffer);
    if (exists < 0)
    {
      fprintf(stderr, "%s not found \n", dent->d_name);
    }
    else
    {
      printf("%s %lld\n", dent->d_name, buffer.st_size);
    }
  }

  // Close directory
  closedir(dir);
  return 0;
}