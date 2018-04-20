#include <stdio.h>
#include <dirent.h>

/**
 * Get Directory Listing
 */
int listdir(const char *path) {
  DIR *dp;
  struct dirent *ep;

  // Open directory
  dp = opendir(path);
  if (dp == NULL) {
    perror("Couldn't open the directory"); // print any errors
    return -1;
  }
  // Repeatly read entries
  while((ep = readdir(dp)))
    printf("   %s\n", ep->d_name);

  // Close directory
  closedir(dp);
  return 0;
}

/**
 * Main Function to Print Listing
 */
int main(int argc, char **argv) {
  int counter = 1;

  // Parse and print command line
  int i;
  printf("   File path: \n");
  for (i = 0; i < argc; i++) {
    printf("   %s\n", argv[i]);
  }

  if (argc == 1)
    listdir(".");

  // Repeatly print entries
  while (++counter <= argc) {
    printf("\n   Print Listing for %s\n", argv[counter-1]);
    listdir(argv[counter-1]);
  }

  return 0;
}