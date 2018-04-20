
#include <dirent.h> 
#include <stdio.h> 

int main(int argc, char **argv) {
  // printf("No. of parameters passed %d\n", argc);
  // printf("parameter vector %s\n", argv);
  
  //declare variables
  DIR *d;
  struct dirent *ent;

  //open dir
  d = opendir(argv[1]);

  //loop through directory contents
  if (d) {
    while ((ent = readdir(d)) != NULL) {
      printf("%s\n", ent->d_name);
    }
    closedir(d);
  }
  return(0);
}