#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *ent;
  DIR *mydir;
  if(argc <= 2) {
    if(argv[1]){
      mydir = opendir(argv[1]);
    }
    else {
      mydir = opendir(".");
    }
    while((ent = readdir(mydir)) != NULL){
      printf("%s\n", ent->d_name);
    }
    closedir(mydir);
  }
  else {
    fprintf(stderr, "Wrong amount of input. Please enter one file path like so: ./lsls Your_File_Path \n");
    exit(1);
  }
  return 0;
}