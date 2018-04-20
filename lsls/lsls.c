#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *dir_arg;
  DIR *d;

  if(argc == 1) {
    dir_arg = ".";
  }
  else if(argc == 2) {
    dir_arg = argv[1];
  }
  else {
    printf(
    "There are too many command line arguments.\n"
    "There are %d command line argument(s),"
    " but there should only be 1 or 2.\n", argc
    );
  }

  // Open directory
  d = opendir(dir_arg);
  printf("Testing: %s\n", d == NULL? "FAIL": "PASS");

  // Repeatly read and print entries
  while(d) {
    struct dirent *ent = readdir(d);
    printf("%s\n", ent->d_name);
  }

  // Close directory
  closedir(d);



  return 0;
}