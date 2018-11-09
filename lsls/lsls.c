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

  if (argc > 2)
  {
    printf("Invalid arguments passed.");
    exit(1);
  }
  else if (argc == 2)
  {
    if ((dir = opendir(argv[1])) != NULL)
    {
      while ((ent = readdir(dir)) != NULL)
      {
        printf("%s\n", ent->d_name);
      }
      closedir(dir);
    }
    else
    {
      printf("Error opening directory.");
      exit(-1);
    }
  }
  else if ((dir = opendir(".")) != NULL)
  {
    while ((ent = readdir(dir)) != NULL)
    {
      printf("%s\n", ent->d_name);
    }
    closedir(dir);
  }
  else
  {
    printf("Error opening directory.");
    exit(-1);
  }

  return 0;
}