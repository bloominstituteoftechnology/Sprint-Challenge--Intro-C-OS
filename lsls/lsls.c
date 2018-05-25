#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

int i;

  printf("There are %d command line argument(s):\n", argc);

  for (i = 0; i < argc; i++) {
      printf("   %s\n", argv[i]);
  }

  // Open directory

DIR * d;
char * path = ".";

d = opendir (path);

if (! d) {
  fprintf (stderr, "Cannot open directory '%s': %s\n", path, strerror (errno));
  exit (EXIT_FAILURE);
}

  // Repeatly read and print entries

while (1) {

  struct dirent * ent;

  ent = readdir (d);
  if (! ent) {
    break;
  }
  printf ("%s\n", ent->d_name);
}

  // Close directory

if (closedir (d)) {
  fprintf (stderr, "Could not close '%s': %s\n", path, strerror (errno));
  exit (EXIT_FAILURE);
}

  return 0;
}