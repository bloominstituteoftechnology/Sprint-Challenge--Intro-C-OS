#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *ent;
  DIR *dir = opendir(argv[1]);

  if (argc == 1)
  {
    dir = opendir(".");
  }

  if (dir != NULL)
  {
    while ((ent = readdir(dir)) != NULL)
    {
      printf("%s\n", ent->d_name);
    }
  }

  closedir(dir);

  return 0;
}