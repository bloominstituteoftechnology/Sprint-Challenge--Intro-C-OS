#include <stdio.h>
#include <dirent.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  int i;
  // Parse command line
  DIR *d = opendir(".");
  // Open directory
  printf("There are %d command line argument(s):\n", argc);
  // Repeatly read and print entries
  for (i = 0; i < argc; i++) {
        printf("   %s\n", argv[i]);
    }
  // Close directory
  closedir(d);
  return 0;
}


    

    
