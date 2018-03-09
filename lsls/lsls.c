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
    printf("Failed to open directory, does this exist?");
    return 1;
  }

  while((directoryEntry = readdir(Directory)) != NULL ){
    printf("Entry: %s\n", directoryEntry->d_name);
  }

  closedir(Directory);

  return 0;
}


  int main(int argc, char **argv)

  char*dirname ="."; //TODO: Magic Character

  //parse command line

  //debug testing

  // int i;

  // printf("There are %d command line argument(s):\n", argc);

  // for (i=0; i < argc; i++) {
  //   printf("    %s\n", argv[i]);
  // }
  // if(argc > 2)
  // {
  //   printf("ERROR: Too many command line arguments.\n");
  //   exit (1); //TODO: exit codes
  // }
  // else if (argc == 1)
  // {
  //   dirname = ".";
  // }
  // else{
  //   dirname= argv[1];
  // }

  //open director

  // DIR *d = opendir(dirname);
  //printf("DEBUG: %p\n", d);
  // if(d == NULL)
  // {
  //   printf("ERROR: Directory not found. \n");
  //   exit(1); //TODO : investing this thing ->
  // }

  // // Repeatly read and print entries


  // struct direct *ent;
  // ent = readdir(d);
  // while (ent != NULL)
  // {
  //   printf("%s\n", ent ->d_name); //todo: investing this thing ->
  //   ent = readdir(d);
  // }

  //close directory

  
  // closedir(d); //todo: verify working

  // return 0:
  // }

  // printf("There are %d command line argument(s): \n", argc);


