#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory
  DIR *d = opendir(".");
  if (d == NULL) // Checks for errors
  {
    printf("\033[31merror\033[37m: no such file or directory\n");
    return 0;
  }
  // Repeatly read and print entries
  struct dirent *id;
  while ((id = readdir(d)) != NULL) {
    printf("%s\n", id->d_name);
  }
  // Close directory
  closedir(d);
  return 0;
}