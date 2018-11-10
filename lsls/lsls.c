#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/wait.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *ent;
  DIR *directory;

  if (argc == 1)
  {
    directory = opendir(".");
  }
  
  if (argc == 2)
  {
    directory = opendir(argv[1]);
  }

  if (directory == NULL) 
  {
    printf("Cannot open directory.");
    exit(1);
  }

  while ((ent = readdir(directory)) != NULL)
  {
    printf("%s\n", ent->d_name);
  }

  closedir(directory);
  return 0;
}