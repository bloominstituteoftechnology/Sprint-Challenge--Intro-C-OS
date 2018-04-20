#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Get Directory Listing
 */
int listdir(const char *path) {
  DIR *dp;
  struct dirent *ep;
  struct stat buf;

  stat(path, &buf);

  // Open directory
  dp = opendir(path);
  if (dp == NULL) {
    perror("Couldn't open the directory"); // print any errors
    return -1;
  }
  // Repeatly read and print entries
  while((ep = readdir(dp)))
    printf("   %6lld %s\n", buf.st_size, ep->d_name);

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
  printf("   File path parsed from command line: \n");
  for (i = 0; i < argc; i++) {
    printf("      %s\n", argv[i]);
  }

  if (argc == 1)
    listdir(".");

  // call listdir helper function to print off directory listing
  while (++counter <= argc) {
    printf("\n   Listing for %s is:\n", argv[counter-1]);
    listdir(argv[counter-1]);
  }

  return 0;
}