#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  DIR *dir;
  struct dirent *ent;
  if (argc < 1) {
      if ((dir = opendir("./")) == NULL) {
          perror ("Cannot open ./");
          exit (1);
      }
  } 
  // Open directory
  else {
    if ((dir = opendir (argv[1])) == NULL) {
          perror ("Cannot open ./");
          exit (1);
      }
  }

  // Repeatly read and print entries

  while ((ent = readdir(dir)) != NULL) {
    printf("%s\n", ent->d_name);
  }

  // Close directory
  closedir(dir);

  return 0;
}