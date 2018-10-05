#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
  * Main
 */
int main(int argc, char **argv)
{

  // Parse command line

  // char pointer to varible that will hold directory we will be accessing
  char *dir;

  // if argc is one then no arguments were given and this is the default
  if (argc == 1) { 

    // set current directory to "."
    dir = ".";

  // if argc is 2 then we have an argument given which is a path
  } else if (argc == 2) {

    // argv[1] is the argument given; which is the path and is set to dir
    // argv is stored as strings and stay as strings
    dir = argv[1];

    // if more than one argument is given an error statement 
  } else {
    fprintf(stderr, "To many arguments given\n");

    // to use exit() function <stdlib.h> needs to be included
    exit(1);
  }

  // Open directory

  // opendir() returns a pointer of DIR type.  
  DIR *dr = opendir(dir);

  // error check if opendir returns NULL
  if (dr == NULL) {
    fprintf(stderr, "cannot open directory\n");
    exit(2);
  } 
  

  // Repeatly read and print entries

  struct dirent *path;

  while((path = readdir(dr)) != NULL) {
    printf("%s\n", path->d_name);
  }

  // Close directory

  closedir(dr);

  return 0;
}
