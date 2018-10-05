#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  // Open directory
  printf("Directory:\n");
  DIR *directory = opendir(argv[1] ? argv[1] : ".");

  if(!directory){
      printf("Error occured. \n");
      exit(-1);
  }

  // Repeatly read and print entries
  struct dirent *file = readdir(directory);


  while ((file = readdir(directory)) != NULL)
  {
    printf("%s \n", file->d_name);
  }

  // Close directory
  closedir(directory);

  return 0;
}