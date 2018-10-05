#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char **argv)
{
  struct dirent *directory_struct;
  DIR *directory;

  if (argc < 2) {
    directory = opendir(".");
  } else {
    directory = opendir(argv[1]);
  }

  if (directory == NULL) {
    printf ("Directory '%s' can't be opened.\n", argv[1]);
    exit(1);
  }

  directory_struct = readdir(directory);

  while (directory_struct != NULL) {
    printf ("[%s]\n", directory_struct->d_name);
    directory_struct = readdir(directory);
  }

  closedir(directory);

  return 0;
}
