#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *ent;
  struct stat buf;
  DIR *dir;

  if (argc == 1)
  {
    dir = opendir(".");
  }
  else
  {
    dir = opendir(argv[1]);
  }

  if (dir != NULL)
  {
    while ((ent = readdir(dir)) != NULL)
    {
      stat(ent->d_name, &buf);
      if ((buf.st_mode & S_IFDIR) != 0)
      {
        printf("<DIR> %s\n", ent->d_name);
      }
      else
      {
        printf("%ld %s\n", buf.st_size, ent->d_name);
      }
    }
  }
  else
  {
    fprintf(stderr, "No such file or directory\n");
    exit(1);
  }

  closedir(dir);

  return 0;
}