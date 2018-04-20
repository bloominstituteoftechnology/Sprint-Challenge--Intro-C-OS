#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  // int i;
  char *args;
  // printf("There are %d command line argument(s):\n", argc);
  // printf( "argv[0]:  %s\n", argv[0] );
  // printf( "argv[1]:  %s\n", argv[1] );
  if (argc == 1) {
    args = argv[0];
  } else if (argc == 2) {
    args = argv[1];
  }

  // Open directory
  DIR *d = opendir(args);
  if (d == NULL) {
    perror ("Directory does not exist.");
    exit (1);
  }
  
  // Repeatly read and print entries
  struct dirent *ent;
  struct stat buf;

  while ((ent = readdir(d)) != NULL) {
    // stat(d, &buf);
    printf("file size is %10lld", buf.st_size);
    printf(" %s\n", ent->d_name);
  }

  // Close directory
  closedir(d);

  return 0;
}