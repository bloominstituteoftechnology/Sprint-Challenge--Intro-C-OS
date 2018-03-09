#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory
  DIR *directory;
  directory = opendir(directory);

  if (directory == NULL)
  {
    printf("haha nope");
  }

  // Repeatly read and print entries
  if ( *directory !== '\0')
  {
    
  }

  // Close directory
  closedir(directory);

  return 0;
}