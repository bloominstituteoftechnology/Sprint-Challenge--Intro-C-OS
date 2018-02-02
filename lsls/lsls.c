#include <stdio.h>
#include <dirent.h> // directory entries

/**
 * Main
 */

// argc is arg counter, argv is arg value
int main(int argc, char **argv)
{
  // directory_name is limited to 10
  char directory_name[10];

  // DIR pointer
  DIR *ptr;

  // structure directory entry points to directory
  struct dirent *directory;
  
  // tell me where to look
  printf("Please enter a directory name: \t");
  
  // string will be provided, it is the directory name
  scanf("%s", directory_name);

  // pointer is now the open directory of the provided name
  ptr = opendir(directory_name);

  // show me the information
  printf("\nDirectory %s\n", directory_name);

  // while the pointer does not point to null (end of directory listing)
  while((directory = readdir(ptr)) != NULL)
  {

    // print the directory names
    printf("%s\n", directory->d_name);
  }

  // close the directory
  closedir(ptr);
  
  // success
  return 0;
}