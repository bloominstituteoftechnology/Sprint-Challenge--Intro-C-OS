#include <stdio.h>
#include <dirent.h>

int printDir(char *path)
{
  DIR *d;
  struct dirent *dir;
  d = opendir(path);
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      printf("%s\n", dir->d_name);
    }
    closedir(d);
  }
  else
  {
    printf("No such \"%s\" directory found\n", path);
    exit(1);
  }
  return 0;
}

/**
 * Main
 */
int main(int argc, char **argv)
{
  char *path;

  if (argc == 1)
  {
    path = ".";
    printDir(path);
  }
  else
  {
    path = argv[1];
    printDir(path);
  }

  return 0;
}