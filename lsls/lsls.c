#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  printf("There are %d command line argument(s):\n", argc);
  char* file = argv[1];
  char* filePath ="";
    for (int i = 2; i < argc; i++) {
      printf("   %s\n", argv[i]);
      filePath = malloc(strlen(file)+ strlen(argv[i]) + 1);
      strcpy(filePath, file);
      strcat(filePath, argv[i]);
      file =  filePath;
    }
    printf("%s\n", filePath);
    
    struct dirent *de;  // Pointer for directory entry
 
    // opendir() returns a pointer of DIR type. 
    DIR *dr = opendir(filePath);
 
    if (dr == NULL)  // opendir returns NULL if couldn't open directory
    {
        // printf("Could not open current directory" );
        dr = opendir(".");
    }

    while ((de = readdir(dr)) != NULL) {
            printf("%s\n", de->d_name);
    }
    closedir(dr);    

  return 0;
}