#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{

  DIR *directory;
  struct dirent *dir;
  
  
  printf("argv[1](path) = %s\n", argv[1]);
  if (argc > 2) {
    fprintf(stderr, "%s", "Too Many Arguments, Please Try Again.\n");
    exit(-1);
  } else if (argc > 0) {
    
    directory = opendir(argv[1]);
    printf(directory);
  } else {
    directory = opendir(".");
  }

  if (directory == NULL) 
  {
    printf("Directory could not be opened.");
    exit(1);
  }


  if (directory)
  {
    while ((dir = readdir(directory)) != NULL)
    {
      printf("%s\n", dir->d_name);
    }
    closedir(directory);
  }

  return 0;
}