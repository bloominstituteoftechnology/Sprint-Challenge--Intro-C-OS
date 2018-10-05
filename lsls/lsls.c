#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *reads; //for readdir
  DIR *dir; //for opendir
  struct stat buf;

  if (argc < 2)
  {
    dir = opendir(".");
    while ((reads = readdir(dir)) != NULL)
    {
      stat(reads->d_name, &buf);
      if (buf.st_mode & S_IFDIR)
      {
        printf("<DIR> %s\n", reads->d_name);
      }
      else if (buf.st_mode & S_IFREG)
      {
        printf("%10lld %s\n", buf.st_size, reads->d_name);
      }
    }
    closedir(dir);
    return 0;
  }

  dir = opendir(argv[1]);

  if (dir == NULL)
  {
    printf("Cannot open directory '%s'\n", argv[1]);
    return 1;
  }

  while ((reads = readdir(dir)) != NULL)
  {
    stat(reads->d_name, &buf);
    if (buf.st_mode & S_IFDIR)
    {
      printf("<DIR> %s\n", reads->d_name);
    }
    else if (buf.st_mode & S_IFREG)
    {
      printf("%10lld %s\n", buf.st_size, reads->d_name);
    }
  }
  closedir(dir);

  return 0;
}