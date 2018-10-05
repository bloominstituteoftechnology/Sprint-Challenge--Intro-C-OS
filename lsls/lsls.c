#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *entry;

  if ((dir = opendir(".")) == NULL)
  {
    fprintf(stderr, "unable to open dir");
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