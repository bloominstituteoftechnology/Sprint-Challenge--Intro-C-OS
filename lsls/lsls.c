#include <stdio.h>
#include <dirent.h>
#include <libgen.h>
#include <sys/types.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  int i;

  printf("%d Command line argument(s):\n", argc);

  for(i = 0; i < argc; i++){
    printf("   %s\n", argv[i]);
  }
  // Open directory
  DIR *d;
  struct dirent *dp;
  // Repeatly read and print entries
  if((d = opendir("."))==NULL){
    perror("Cannot open .");
  }
  while ((dp = readdir (d)) != NULL){
    printf("  %s\n", argv[i]);
  }
  // Close directory
  closedir(d);
  return 0;
}