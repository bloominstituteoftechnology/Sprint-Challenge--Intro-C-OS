#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *pDirent;
  DIR *pDir;

  // Parse command line
  if (argc == 1) //no directory given, only ./lsls.exe was called
  {
    pDir = opendir(".");
  }
  else if (argc == 2)   // a directory was given, 2nd index ([1]) is the directory
  {
    pDir = opendir(argv[1]);
  }
  else     // incorrect usage of ./lsls.exe
  {
    printf("Usage: ./lsls.exe <directory name>\n");
    return 1;
  }

  // Open directory
  if (pDir == NULL)  //checks if the directory is null
  {
    printf("Can't open dir %s \n", argv[1]);
    return 1;
  }

  // Repeatly read and print entries
  while ((pDirent = readdir(pDir)) != NULL)  //until the entire directory is iterated through
  {
    printf("[%s]\n", pDirent->d_name);
  }

  // Close directory
  closedir(pDir);

  return 0;
}