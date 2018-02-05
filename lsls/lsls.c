#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
  // Parse command line
  // Open directory
  // Repeatly read and print entries
  // Close directory
  int len;
  struct dirent *pDirent;
  DIR *pDir;

  if (argc < 2) 
  {
    pDir = opendir(".");
  }

  else pDir = opendir (argv[1]);
  
  if (pDir == NULL) 
  {
    printf ("Cannot open directory '%s'\n", argv[1]);
    return 1;
  }

  while ((pDirent = readdir(pDir)) != NULL) 
  {
    printf ("%10lld %s\n", 1111111111, pDirent->d_name);
  }
  closedir (pDir);
  return 0;
}

