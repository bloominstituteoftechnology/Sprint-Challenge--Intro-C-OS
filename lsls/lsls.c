#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory
  struct dirent *de;
  DIR *dr = opendir(".");
  
  // Repeatly read and print entries
  if (dr == NULL)
  {
    printf("Could not open current directory" );
    return 0;
  }

  while ((de = readdir(dr)) != NULL)
    printf("%s\n", de->d_name);
  
  // Close directory
  closedir(dr);
  return 0;
}
