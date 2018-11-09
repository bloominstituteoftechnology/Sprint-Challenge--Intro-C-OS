#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * Main
 */
  int main(int argc, char **argv)
{
  // Parse command line
  // DIR *dir;
  // struct dirent *pDirent;

  struct stat buf;
  int exists;
  DIR *dir;
  struct dirent *pDirent;

  if (argc < 2)
  {
    printf("Usage: print <dirname>\n");
  }

  // Open directory
  /*The opendir() function opens a directory stream corresponding to the directory name, 
  and returns a pointer to the directory stream. 
  The stream is positioned at the first entry in the directory.*/

 if (argv[1] == NULL)
  {
    dir = opendir(".");
  }
  else
  {
    dir = opendir(argv[1]);
  }

  if (dir == NULL)
  {
    printf("Cannot open directory %s\n", argv[1]);
    return 1;
  }

  for (pDirent = readdir(dir); pDirent != NULL; pDirent = readdir(dir)) {
    exists = stat(pDirent->d_name, &buf);
    if (exists < 0) {
      fprintf(stderr, "%s not found\n", pDirent->d_name);
    } else {
      printf("%s %ld\n", pDirent->d_name, buf.st_size);
    }
  }

  // Repeatly read and print entries
  // while ((pDirent = readdir(dir)) != NULL)
  // {
  //   printf("%s\n", pDirent->d_name);
  // }

  // Close directory
  closedir(dir);
  return 0;
}

