#include <stdio.h>
#include <dirent.h>

int main(int argc, char **argv)
{ 
  /* error handling for multiple CLI arguments */
  /* also implemented to prevent compilation warning from unused argc param */
  if (argc > 2) {
    printf("Too many arguments supplied by the user. Please try again.\n");
    return 0;
  }
  /* open specified directory if supplied by user, otherwise opens current dir */
  DIR *directory = opendir(argv[1] ? argv[1] : ".");
  /* conditional that executes if directory exists...should always execute */
  if (directory) {
    /* retrieve sturct dirent (functionality provided by dirent header */
    struct dirent *next = readdir(directory);
    /* loop until NULL indicates no more directory entries */
    while ((next = readdir(directory)) != NULL) {
      /* print the string from the accessed member */
      printf("%s\n", next->d_name);
    }
  /* internal error handling */
  } else {
    printf("An error occured while reading the data. Please try again.");
  }
  /* close the directory */
  closedir(directory);
  /* return out of program */
  return 0;
}
