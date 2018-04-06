#include <stdio.h>
#include <stdlib.h>
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
        sprintf(file_path, "%s %s %s", path, "/", dir->d_name);
        
        stat(file_path, &buff);
        
        if (S_IFDIR & buff.st_mode)
        {
          printf("<DIR> %s\n", dir->d_name);
        }
        else if (S_IFREG & buff.st_mode)
        {
          printf("%lld %s\n", buff.st_size, dir->d_name);
        }
        else
        {
          printf("<NO DIR> %s\n", dir->d_name);
        }
    
        file_path[0] = '\0';
      }
      closedir(d);
    }
    else
    {
      printf("This directory \"%s\" not found\n", path);
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