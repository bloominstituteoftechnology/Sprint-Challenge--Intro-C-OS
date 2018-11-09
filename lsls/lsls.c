#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  int i;

  printf("%d Command line:\n", argc);

  for(i = 0; i < argc; i++){
    printf("$%s\n", argv[i]);
    puts(argv[i]);
  }
  // Open directory
  DIR *dirname;
  // Pointer for directory
  struct dirent *dr;
  
  // opendir() returns a pointer of DIR type. 
  dirname = opendir(".");

  // Repeatly read and print entries
  
  // If directory cannot be opened return message 
  if(dirname == NULL){
    printf("Directory does not exist.\n");
    exit(1);
  }
  while ((dr = readdir(dirname)) != NULL){
    printf(" %s\n", dr -> d_name);
  }

  // Close directory
  closedir(dirname);
  
  return 0;
}