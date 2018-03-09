#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  char *dir;
  struct dirent *de;
  // Parse command line
  if (argc > 1) { // get the dir the user inputted
    dir = argv[1];
  } else {
     dir = ".";
  }
  // Open directory
  // opendir() returns a pointer of DIR type. 
    DIR *dr = opendir(dir); 
 
    if (dr == NULL)  // opendir returns NULL if couldn't open directory
    {
      printf("Could not open current directory" );
      return 1;
    }
  // Repeatly read and print entries
    while ((de = readdir(dr)) != NULL)
      printf("%s\n", de->d_name);
 
  // Close directory
  closedir(dr); 
  return 0;
}