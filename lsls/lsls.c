#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *reads; //for readdir
  DIR *dir; //for opendir

  if (argc < 2)
  {
    dir = opendir(".");
    while ((reads = readdir(dir)) != NULL)
    {
      printf("%s\n", reads->d_name);
    }
    closedir(dir);
    printf("\nUsage: ./lsls <dirname>\n");
    return 1;
  }
  dir = opendir(argv[1]);

  if (dir == NULL)
  {
    printf("Cannot open directory '%s'\n", argv[1]);
    return 1;
  }

  while ((reads = readdir(dir)) != NULL)
  {
    printf("%s\n", reads->d_name);
  }
  closedir(dir);

  return 0;
}