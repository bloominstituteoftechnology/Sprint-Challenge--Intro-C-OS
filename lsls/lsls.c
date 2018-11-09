#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *path;
  if (argc == 1)
  {
    // If no arguments print set path as current directory
    *path = "."
  }
  else
  {
    // Set path as argument
    *path = argv[1];
  }

  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}
