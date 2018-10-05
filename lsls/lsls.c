#include <stdio.h>
#include <dirent.h>
#include <stdlib.h> //added for exit process

/**
 * Main
 */

int main(int argc, char **argv)
{
  // **Parse command line**

  char *directname;
  // argc==0 doesnt work.  Need to start w 1 at least(google fu) to start program.
  if (argc == 1){
    // going to set dir that im looking for to "."
    directname = ".";
  }
  else if (argc == 2){
    directname = argv[1]; // starting path .
  }
  else{
    fprintf(stderr, "ERROR: file unable to open\n");
    exit(1);
  }
  // **Open directory**

  //defining pointer
  DIR *directory = opendir(directname);
  // error checking
  if (directory == NULL){
    fprintf(stderr, "unable to open directory %s\n", directname);
    exit(11); //different error (changing #)
  }

  // **Repeatly read and print entries**

  //directory stream at "directory" is read, loop through directory contents
  //readdir has current pointer and pointer for following element and "positions the directory stream at next entry(per docs"
  struct dirent *entries; //pointer created
  while ((entries = readdir(directory)) != NULL){
    printf("%s\n", entries->d_name); //name of entry per docs (per dirent structure docs)
  }

  // **Close directory**

  closedir(directory);

  return 0;
}