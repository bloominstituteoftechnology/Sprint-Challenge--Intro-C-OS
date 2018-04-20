#include <stdio.h>
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

  DIR *dir;
  struct dirent *dent;
  struct stat buffer;
  // char buffer[50];
  // strcpy(buffer, argv[1]);

  // if (dir != NULL) {
  //   while((dent=readdir(dir)) != NULL)
  //     printf(dent -> d_name);
  // }
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
    printf("There is an error opening the directory \n");
    exit(0);
  }

  while ((dent = readdir(dir)) != NULL)
  {
    stat(entry-- > d_name, &buffer);
    if ()
  }
  close(dir);
  return 0;
}