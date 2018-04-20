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

  // Open directory
  DIR *d = opendir(".");
  
  // Repeatly read and print entries
  // readdir();
  if (d == NULL) {
    // return 0;
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