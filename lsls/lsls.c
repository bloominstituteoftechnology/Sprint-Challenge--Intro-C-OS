#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory

  // Repeatly read and print entries

  // Close directory
  struct stat buffer;
  int exists;
  DIR *dir;
  struct dirent *dent;

  if (argc == 1)
  {
    dir = opendir(".");
  }
  else
  {
    while (argv[1][0] == '/')
    {
      argv[1]++;
    }
    dir = opendir(argv[1]);
  }

  if (dir == NULL)
  {
    fprintf(stderr, "Could'nt open \".\"\n");
    exit(1);
  }

  for (dent = readdir(dir); dent != NULL; dent = readdir(dir))
  {
    exists = stat(dent->d_name, &buffer);
    if (exists < 0)
    {
      fprintf(stderr, "%s not found \n", dent->d_name);
    }
    else
    {
      printf("%s %lld\n", dent->d_name, buffer.st_size);
    }
  }
  // char buffer[50];
  // strcpy(buffer, argv[1]);

  // if (dir != NULL) {
  //   while((dent=readdir(dir)) != NULL)
  //     printf(dent -> d_name);
  // }

  // if (argc == 1)
  // {
  //   dir = opendir(".");
  // }
  // else
  // {
  //   while (argv[1][0] == '/')
  //   {
  //     argv[1]++;
  //   }
  //   dir = opendir(argv[1]);
  // }

  // if (dir == NULL)
  // {
  //   printf("There is an error opening the directory \n");
  //   exit(0);
  // }

  // while ((dent = readdir(dir)) != NULL)
  // {
  //   stat(entry-- > d_name, &buffer);
  //   if ()
  // }
  closedir(dir);
  return 0;
}