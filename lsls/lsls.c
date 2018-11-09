#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv) //equivilent to *argv[]
{
  // int i;
  // printf("%i\n", argc);
  // printf("%s\n", argv[0]);
  // printf("There are %d command line argument(s):\n", argc-1);

  // for (i = 1; i < argc; i++) {
  //     printf("   %s\n", argv[i]);
  // }
  
  struct dirent *entries;
  DIR *folder;

  if (argc < 2) {
      folder = opendir (".");
      while ((entries = readdir(folder)) != NULL) {
          printf ("[%s]\n", entries->d_name);
      } 
      return 1;
  }
    
  folder = opendir (argv[1]);
  if (folder == NULL) {
      printf ("Cannot open directory '%s'\n", argv[1]);
      exit(1);
      // return 1;
  }

  while ((entries = readdir(folder)) != NULL) {
      printf ("[%s]\n", entries->d_name);//rough equivilent of dot notation essentially

      // int stat(char * argv, struct stat *buf);
      struct stat buf;

      stat(entries->d_name, &buf);

      printf("file size is %10ld\n", buf.st_size);
  }
  closedir (folder);
  return 0;

}