#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line


  // Open directory

  // Repeatly read and print entries

  // Close directory
  struct dirent *de;  // Pointer for directory entry 

  // opendir() returns a pointer of DIR type.  
  char* parse = argv[1];
  
  DIR *dr = opendir(parse); 

  if (dr == NULL)  // opendir returns NULL if couldn't open directory 
  { 
      printf("Could not open directory %s\n", parse ); 
      return 0; 
  } 

  while ((de = readdir(dr)) != NULL) 
          printf("%s\n", de->d_name); 

  // printf("%s\n", parse);
  printf("---end of directory--- \n");
  closedir(dr);  

  return 0;
}