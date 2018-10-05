#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *ent;
  DIR *dir;

  if (argc == 1)
  {
    dir = opendir(".");
  }
  else
  {
    dir = opendir(argv[1]);
  }

  if (dir != NULL)
  {
    while ((ent = readdir(dir)) != NULL)
    {
      printf("%s\n", ent->d_name);
    }
  }
  else
  {
    fprintf(stderr, "No such file or directory\n");
    exit(1);
  }

  closedir(dir);

  return 0;
}