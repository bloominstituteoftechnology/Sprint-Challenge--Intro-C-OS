#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *ent;
  struct stat buf;

  // Parse command line
  if (argc < 1)
  {
    exit(1);
  }
  else if (argc == 1)
  {
    // Open the current directory
    if ((dir = opendir("./")) == NULL)
    {
      perror("Cannot open ./");
      exit(1);
    }
  }
  else
  {
    // Open the given directory
    if ((dir = opendir(argv[1])) == NULL)
    {
      char errMsg[1000];
      strcat(errMsg, argv[1]);
      perror(errMsg);
      exit(1);
    }
  }

  // Repeatly read and print entries
  ent = readdir(dir);

  while (ent != NULL)
  {
    // get the file sizes
    stat(ent->d_name, &buf);

    printf("%10lld %s\n", buf.st_size, ent->d_name);
    ent = readdir(dir);
  }

  // Close directory
  closedir(dir);

  return 0;
}