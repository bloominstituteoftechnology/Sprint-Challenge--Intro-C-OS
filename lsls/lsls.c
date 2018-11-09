#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
DIR *d;
struct dirent *dir;
if(argc == 1){
  printf("bruh gimme somethng to work with here \n");
  //how you gun ask me to exit and not incldue the stdlib smdh
  exit(1);
} else{
  // print out the arguments
  printf("here they are all you had to do was speak on ye\n");
  for(int i = 1; i<argc; i++){
    printf("%d. %s\n", i, argv[i] );
  }
}
  // Open directory
  //pass in argv duh that's the current dir.
d = opendir(argv[1]);
if(d){
    // Repeatly read and print entries
  while((dir = readdir(d)) != NULL){
    //you should print the field `d_name` from your `struct dirent *`
    printf("%s\n", dir->d_name);
  }
    // Close directory
  closedir(d);
}
  return 0;
}
