#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory
  DIR *dir;
  struct dirent *ent;
  char path = ".";

  if (argc == 1)
  {
    printf("1 argument received, Directory: %p\n", path);
  } 
  else if (argc == 2) 
  {
    printf("2 args received\n");
    path = argv[1];
    printf("Directory: %p\n", path);
  } 
  else
  {
    printf("Error! Too many arguments!\n");
    exit(1);
  }

  dir = opendir(path);
  // handle error if null
  if (dir == NULL)
  {
    printf("Error! Cannot open directory\n");
    exit(1);
  }
  
  // Repeatly read and print entries
  while ( (ent = readdir(dir)) != NULL )
  {
    printf("%s\n", ent->d_name);
  }


  // Close directory
  closedir(dir);
  return 0;
}