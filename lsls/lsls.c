#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{

  DIR *dir;
  
  printf("There are %d command line argument(s):\n", argc);
  for ( int i = 0; i < argc; i++) {
    printf("   %s\n", argv[i]);
  }
  if(argc < 2) 
  {
  dir = opendir("."); 
  } else 
  {
  dir = opendir(argv[1]); 
  }
  
  if ( dir == NULL)
  {
    printf("Not Found");
    exit(0);
  } else 
  {  do 
  {
    printf( "%s\n", readdir(dir)->d_name);
  }
    while (readdir(dir)!=NULL);
  }
  
   closedir(dir);
   return 0;
  }