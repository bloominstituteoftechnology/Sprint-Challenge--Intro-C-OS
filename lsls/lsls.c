#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *entry;

  printf("argc: %d\n", argc);
  printf("argv[1]: %s\n", argv[1]);

  if (argv[1] != NULL)
  {
    dir = opendir(argv[1]);
  }
  else
  {
    dir = opendir(".");
  }

  if (dir == NULL)
  {
    fprintf(stderr, "unable to open dir\n");
  }
  else
  {
    puts("contents of DIR:");
    while ((entry = readdir(dir)) != NULL)
    {
      printf("  %s\n", entry->d_name);
    }
    closedir(dir);
  }

  return 0;
}