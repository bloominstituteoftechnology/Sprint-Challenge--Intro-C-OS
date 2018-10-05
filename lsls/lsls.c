#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  DIR *dr;
  struct dirent *de;
  // Open directory
  if (argc == 1)
  {
    dr = opendir(".");
  }
  else if (argc == 2)
  {
    dr = opendir(argv[1]);
  }
  else
  {
    fprintf(stderr, "There is an error with file opening\n");
  }
  // Repeatly read and print entries
  if (dr == NULL)
  {
    fprintf(stderr, "Error! Something is wrong\n");
    exit(1);
  }
  else{
    while ((de = readdir(dr)) != NULL)
      printf("%s\n", de->d_name);
  }
  // Close directory
  closedir(dr);
  return 0;
}