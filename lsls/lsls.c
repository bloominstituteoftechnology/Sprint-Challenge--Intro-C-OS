#include <stdio.h>
#include <dirent.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  int i;
  
  printf("   File path: \n");
  for (i = 0; i < argc; i++) {
    printf("   %s\n", argv[i]);
  }

  // Open directory
  DIR *dp;
  struct dirent *ep;
  dp = opendir("./");

  // Repeatly read and print entries
  if (dp != NULL) {
    printf("\n   Directory Listing: \n");
    while (ep = readdir(dp)) {
      printf("   %s\n", ep->d_name);
    }
  // Close directory
    (void) closedir(dp);
  } else {
    perror("Couldn't open the directory"); // print any errors
  }

  return 0;
}