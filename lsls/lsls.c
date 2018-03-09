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
      // get absolut path of file
      sprintf(file_path, "%s%s%s", path, "/", dir->d_name);

      // get the file info and store in the buff
      stat(file_path, &buff);

      // check if DIR(non-zero) or FILE(zero)
      if (S_IFDIR & buff.st_mode)
      {
        printf("<DIR> %s\n", dir->d_name);
      }
      else
      {
        printf("%lld %s\n", buff.st_size, dir->d_name);
      }

      // clearn file path buff
      file_path[0] = '\0';
    }
    closedir(d);
  }
  else
  {
    // print error message if no directory found
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

  // if only one command line argument, open current "." directory
  if (argc == 1)
  {
    path = ".";

    // print whole directory
    printDir(path);
  }
  else
  {
    // if second argument for specific dir path, print that dir
    path = argv[1];
    printDir(path);
  }

  return 0;
}