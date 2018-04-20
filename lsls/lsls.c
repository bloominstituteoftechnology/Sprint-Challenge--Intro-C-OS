#include <stdio.h>
#include <dirent.h>


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
  d = opendir(".");
  // Repeatly read and print entries
  struct dirent *ent;

  if(d != NULL) {
    while((ent = readdir(d)) != NULL) {
      printf("%s\n", ent->d_name);
    }
  }
  // Close directory
  closedir(d);
    
  return 0;
}


    

    
