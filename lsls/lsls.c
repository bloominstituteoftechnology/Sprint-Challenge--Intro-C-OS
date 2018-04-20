#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory

  // Repeatly read and print entries

  // Close directory

  DIR *dir;
  struct dirent *dent;
  char buffer[50];
  strcpy(buffer, argv[1]);
  dir = opendir(buffer);
  if (dir != NULL) {
    while((dent=readdir(dir)) != NULL)
      printf(dent -> d_name);
  }
  close(dir);
  return 0;
}