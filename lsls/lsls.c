#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  char *dirname;
  if (argc==1) {
    dirname= '.';
  }
  else if (argc == 2) {
    dirname= argv[1];
  }

  // Open directory

  DIR *d = opendir(dirname);

  // Repeatly read and print entries

  struct dirent *ent;

  while((ent= readdir(d)) !=NULL) {
    printf('%s\n', ent->d_name);
  }

  // Close directory

  closedir(d);

  return 0;
}