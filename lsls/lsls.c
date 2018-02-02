#include <stdio.h>
#include <stdlib.h>  //strtol
#include <dirent.h>
#include <sys/stat.h>
 
int main(int argc, char *argv[]) {
    struct dirent *directoryEntry;  // Pointer for directory entry
    DIR *directoryName; // opendir() returns a pointer of DIR type. 
    struct stat buf;

    // If no arguments set directory to "."
    // If argument provided, set directory to argument
    if (argc < 2) {
      directoryName = opendir(".");
      printf("\nDirectory Name = %s\n", argv[0]);
    } else {
      directoryName = opendir(argv[1]);
      printf("\nDirectory Name = %s\n", argv[1]);
    }

    while ((directoryEntry = readdir(directoryName)) != NULL) {
            int * nameRef = directoryEntry->d_name;
            stat(nameRef, &buf);
            int * nameSize = buf.st_size;

            if (nameSize == 4096) {
              printf( "      <DIR>  %s\n", nameRef);
            } else {
              printf( "%10lld B  %s\n", nameSize, nameRef);
            }
            
            
    }
 
    closedir(directoryName);    
    return 0;
}