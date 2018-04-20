#include <stdio.h>
#include <dirent.h>

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
  int len;
  struct dirent *ent;
  DIR *pDir;

  if (argc < 2) {
    printf ("Usage: testprog <dirname>\n");
    return 1;
  }
  pDir = opendir(argv[1]);
  if (pDir == NULL)
  {
    printf ("Cannot open directory '%s' \n", argv[1]);
    return 1;
  }


  // Repeatly read and print entries
  while ((ent = readdir(pDir)) != NULL)
  {
    printf ("[%s]\n", ent->d_name);
  }

  // Close directory

  closedir (pDir);

  return 0;
}