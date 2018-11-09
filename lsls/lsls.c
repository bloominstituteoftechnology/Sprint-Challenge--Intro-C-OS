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
    exit(0);
  }

  ent = readdir(directory);
  // pid_t pid = fork();

  // if (pid == 0) {
  //   printf("%s\n", ent->d_name);
  //   exit(1);
  // } else {
  //   wait(NULL);
  // }

  while (ent != NULL)
  {
    printf("%scheck\n", ent->d_name);
  }


  closedir(directory);
  return 0;
}