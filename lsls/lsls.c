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
  char *args;
  // printf("There are %d command line argument(s):\n", argc);
  // printf( "argv[0]:  %s\n", argv[0] );
  // printf( "argv[1]:  %s\n", argv[1] );
  if (argc == 1) {
    args = ".";
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
  char link[128];

  while ((ent = readdir(d)) != NULL) {
    sprintf(link, "%s/%s", args, ent->d_name);
    stat(link, &buf);
    if((buf.st_mode & S_IFDIR) != 0) {
      printf("<DIR>     %s\n", ent->d_name);
    } else if ((buf.st_mode & S_IFREG) != 0) {
      printf("%10lld   %s\n", buf.st_size, ent->d_name);
    } else {
      printf(" %s\n", ent->d_name);
    }
  }

  // Close directory
  closedir(d);

  return 0;
}