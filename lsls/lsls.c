#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *entry;
  struct stat buf;

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
      stat(entry->d_name, &buf);
      printf("%10d  %s\n", (unsigned int)buf.st_size, entry->d_name);
    }
    closedir(dir);
  }

  return 0;
}