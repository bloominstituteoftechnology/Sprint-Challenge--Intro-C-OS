#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
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
  struct stat buf;

  while ((file = readdir(directory)) != NULL)
  {
    stat(file->d_name, &buf);
    printf("%10lld %s \n", buf.st_size, file->d_name);
  }

  // Close directory
  closedir(directory);

  return 0;
}