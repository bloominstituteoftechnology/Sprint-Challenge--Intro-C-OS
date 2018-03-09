#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  char defaultDirectory[2] = ".";
  struct dirent *directoryEntry;
  DIR *Directory;

  Directory = argc < 2 ? opendir(defaultDirectory) : opendir(argv[1]);
  if(Directory == NULL) {
    printf("Failed to open directory, must not exist");
    exit();
  }

  while((directoryEntry = readdir(Directory)) != NULL ){
    printf("Entry: %s\n", directoryEntry->d_name);
  }

  closedir(Directory);

  return 0;
}