#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int printDir(char *path)
{
  DIR *d;
  struct dirent *dir;
  struct stat buff;
  char file_path[128];

  d = opendir(path);
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      strcat(file_path, path);
      strcat(file_path, "/");
      strcat(file_path, dir->d_name);
      stat(file_path, &buff);
      printf("%lld %s\n", buff.st_size, dir->d_name);
      file_path[0] = '\0';
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