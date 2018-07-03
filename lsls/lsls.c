#include <stdio.h>
#include <dirent.h>
#include <stdlib.h> /* included for exit() use requested in specs */

int main(int argc, char **argv)
{ 
  /* custom error handling for extra CLI arguments */
  /* also implemented to prevent compilation warning from unused (required) argc parameter */
  if (argc > 2) {
    /* error message */
    printf("Too many arguments supplied by the user. Please try again.\n");
    /* exit as instructed in specs */
    exit(-1);
  }
  /* open specified directory if supplied by user, otherwise opens current dir */
  DIR *directory = opendir(argv[1] ? argv[1] : ".");
  /* conditional that executes if directory exists */
  if (directory) {
    /* retrieve struct dirent (function provided by dirent header */
    struct dirent *next = readdir(directory);
    /* loop until NULL indicates no more directory entries */
    while ((next = readdir(directory)) != NULL) {
      /* print the string from the accessed member */
      printf("%s\n", next->d_name);
    }
  /* error handling */
  } else {
    /* error message */
    printf("An error occured while reading the data. Please try again.\n");
    /* exit as instructed in specs */
    exit(-1);
  }
  /* close the directory */
  closedir(directory);
  /* return out of program */
  return 0;
}
