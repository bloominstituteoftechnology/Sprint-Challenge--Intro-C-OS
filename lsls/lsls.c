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
  // Parse command line

  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}