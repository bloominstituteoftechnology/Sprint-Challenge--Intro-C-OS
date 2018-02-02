#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  // Open directory
  // Repeatedly read and print entries
  // Close directory

  int i;
  struct dirent *d;

  printf("I see %d directories: \n", argc);

  for (i=0; i<argc; i++) {
    printf("%s\n", argv[i]);
  }


  if (dir == NULL)
  {
    printf("Can't find that directory");
    return 0;
  }

  struct dirent {
    ino_t d_ino;
    char d_name[];
  }

  while ((d = readdir(dir)) != NULL)
    printf("%s\n", d->d_name);

  closedir(dir);
  return 0;
}