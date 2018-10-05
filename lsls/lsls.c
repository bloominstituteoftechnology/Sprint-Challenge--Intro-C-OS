#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  char *path;

  // Parse command line
  if(argc > 1){
    path = argv[1];
  }
  else{
    path = ".";
  }


  // Open directory
  DIR *directory = opendir(path);
  // Repeatly read and print entries
  if(directory){
    struct dirent *entry = readdir(directory);
    while(entry){
      printf("%s\n", entry->d_name);
      entry = readdir(directory);
    }
  }
  else{
    printf("Error opening directory\n");
    exit(1);
  }

  
  // Close directory
  closedir(directory);

  return 0;
}