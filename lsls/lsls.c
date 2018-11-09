#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
  // steps
  // Parse command line
  
  // Open directory
  
  // Repeatly read and print entries

  // Close directory



int main(int argc, char **argv)
{
  char commandLine[9892];
  int pid = fork();
  
  
  if (pid < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  }else if (pid == 0) {

  }else {
    wait(NULL);


  }

  return 0;
}
