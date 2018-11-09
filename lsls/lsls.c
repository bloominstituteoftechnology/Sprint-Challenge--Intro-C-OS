#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  int i;

  printf("%d Command line argument(s):\n", argc);

  for(i = 0; i < argc; i++){
    printf("$%s\n", argv[i]);
    puts(argv[i]);
  }
  // Open directory
  DIR *d;
  struct dirent *dp;

  d = opendir(argv[1]);
  // Repeatly read and print entries
  if(d == NULL){
    printf("Cannot open does not exist.\n");
    exit(1);
  }
  while ((dp = readdir(d)) != '\0'){
    printf("directory item: %s\n", dp -> d_name);
  }
  // Close directory
  closedir(d);
  return 0;
}