#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>


/**
 * Main
 */
int main(int argc, char **argv)
{
  // int i;
  // printf("There are %d command line argument(s):\n", argc);
  // // Parse command line
  //   for (i = 0; i < argc; i++) {
      
  //       printf("   %s\n", argv[i]);
  //       printf("argc %d", argc);
  //   }
  DIR *d;
  // Open directory
  int error = 0;
  d = opendir(char *path);
  // Repeatly read and print entries
  if(d == NULL ) {
    d = opendir(".");
  }
  struct dirent *ent;
  if(d != NULL) {
    while((ent = readdir(d)) != NULL) {
      printf("%s\n", ent->d_name);
    }
  } else if(error == 0) {
    closedir(d);  
    printf("error occured");
    exit(1);
  }

  // Close directory
  closedir(d);   
  return 0;
}


    

    
