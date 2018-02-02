#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  int i;

  struct dirent *tDirent;

  DIR *tDir;

  if (argc < 2) {
    tDir = opendir(".");
    if (tDir == NULL) {
      printf("Cannot open directory \n");
    }
    while ((tDirent = readdir(tDir)) != NULL) {
      printf ("[%s]\n", tDirent->d_name);
    }
    closedir (tDir); 
  } else {
    for (i = 1; i < argc; i++) {
      tDir = opendir(argv[i]);
      if (tDir == NULL) {
        printf("Cannot open directory %s\n", argv[i]);
      }
      while ((tDirent = readdir(tDir)) != NULL) {
        printf ("[%s]\n", tDirent->d_name);
      }
      closedir (tDir);
    }
  }

  return 0;
}