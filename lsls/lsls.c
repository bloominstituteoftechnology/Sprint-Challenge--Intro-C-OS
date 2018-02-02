#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */

// this parses the number of args passed in:
// lsls.exe returns "The 0 arg is: lsls.exe"
// lsls.exe . returns "The 0 arg is: lsls.exe \ The 1 arg is: ."
// argc is arg counter, argv is arg value
//int main(int argc, char **argv)
int main(void)
// {

//   for (int i = 0; i < argc; i++) {
//     printf("The %2d arg is: %s\n", i, argv[i]);
//   }

struct dirent *de;
DIR *dr = opendir(".");

if (dr == NULL) {
  printf("Could not open current directory");
  return 0;
}
while ((de = readdir(dr)) != NULL)
  printf("%s\n", de->d_name);
  closedir(dr);

  // Parse command line

  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}