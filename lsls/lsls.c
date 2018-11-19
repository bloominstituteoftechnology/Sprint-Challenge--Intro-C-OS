#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)

// argc is number of arguements
// argv is is a one-dimensional array of strings
// the program running is the first arguemen 
// the second command line arguement is the directory name
// initialize the struct dirent *read and the DIR *d
// set d to opendir with the second command line arguement
// if there is no second arguement then open current directory (.)
// if opendir d is NULL, throw an error message
// while the next directory is not NULL use readdir to assign to read and then print the name of the directory

{
  // Parse command line
  

  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}