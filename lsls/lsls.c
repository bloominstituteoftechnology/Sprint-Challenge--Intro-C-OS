#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h> 
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  int len;
  struct dirent *pDirent;
  DIR *pDir;

  //Initialize a stat buffer to hold directory sizes:
  struct stat sizebuf;

  //Initialize a buffer to hold the absolute path of each item in the directory:
  char pathbuf[PATH_MAX + 1];

  // Parse command line
  if (argc < 2) {
      printf ("Usage: testprog <dirname>\n");
      return 1;
  }
  
  // Open directory
  pDir = opendir (argv[1]);
  if (pDir == NULL) {
      printf ("Cannot open directory '%s'\n", argv[1]);
      // printf("Path is:%s", argv[1]);
      return 1;
  }
  
  // Repeatly read and print entries
  while ((pDirent = readdir(pDir)) != NULL) {    

      //Take entry and get it's absolute path using realpath and place into the path buffer
      realpath(pDirent->d_name, pathbuf);

      //Calculate the size of the path in path buff using state and place into the size buffer
      stat(pathbuf, &sizebuf);

      // Pring the size and the name in one line
      printf ("%10lld %s\n", sizebuf.st_size, pDirent->d_name);
  }
  
  // Close directory
  closedir (pDir);
 
  return 0;
}