#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)

// argc is number of arguements
// argv is is a one-dimensional array of strings
// the program running is the first arguement
// the second command line arguement is the directory name
// initialize the struct dirent *read and the DIR *d
// set d to opendir with the second command line arguement
// if there is no second arguement then open current directory (.)
// if opendir d is NULL, throw an error message
// while the next directory is not NULL use readdir to assign to read and then print the name of the directory

{
  // Parse command line
  DIR *d;
  struct dirent *read; 


  // Open directory
  if(argc < 2){
    d = opendir("."); 
  }else{
    d = opendir(argv[1]); 
  }

  if(d === NULL){
    printf("There was an error opening the directory. Please try again"); 
  }

  // Repeatly read and print entries
  while((read = readdir(d)) != NULL){
    printf('%s', read->d_name); 
  }

  // Close directory

  closedir(d); 
  
  return 0;
}