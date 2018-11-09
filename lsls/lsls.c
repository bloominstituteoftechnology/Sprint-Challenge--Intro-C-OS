#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  int i;
  printf("%s\n", argv[1]);
  printf("There are %d command line argument(s):\n", argc-1);

  for (i = 1; i < argc; i++) {
      printf("   %s\n", argv[i]);
  }
  
  struct dirent *entries;
  DIR *folder;

  if (argc < 2) {
      printf ("Usage: testprog <dirname>\ninclude folder to open or '.'.");
      return 1;
  }
    
  folder = opendir (argv[1]);
  if (folder == NULL) {
      printf ("Cannot open directory '%s'\n", argv[1]);
      return 1;
  }

  while ((entries = readdir(folder)) != NULL) {
      printf ("[%s]\n", entries->d_name);
  }
  closedir (folder);
  return 0;
  
  // Parse command line

  // Open directory

  // Repeatly read and print entries

  // Close directory

}