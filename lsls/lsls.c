#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  char * dirRequest;
  // Parse command line
  if (argc == 1){
    dirRequest = ".";
  }
  else{
    dirRequest = argv[1];
  }
  // Open directory
   DIR * opendirectory =  opendir(dirRequest);
   if (opendirectory == NULL){
     printf("I'm afraid I can't do that");
   }
  // Repeatly read and print entries
     struct dirent *files;
     files =  readdir(opendirectory);
    while(files != NULL){
      printf("%s\n", files->d_name);
      files =  readdir(opendirectory);

    }
  // Close directory
  closedir(opendirectory);
  return 0;
}