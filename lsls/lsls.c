#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *ent;

  // Parse command line
  int i;
  char *args;
  // printf("There are %d command line argument(s):\n", argc);
  // printf( "argv[0]:  %s\n", argv[0] );

  for (i = 0; i < argc; i++) {
    // printf("   %s\n", argv[1]);
    args = argv[i];
  }

  // Open directory
  DIR *d = opendir(args);
  
  // Repeatly read and print entries
  // readdir();
  if (d == NULL) {
    perror ("Cannot open .");
    exit (1);
  }
  while ((ent = readdir(d)) != NULL) {
    printf("%s\n",ent->d_name);
  }

  // Close directory
  closedir(d);

  return 0;
}