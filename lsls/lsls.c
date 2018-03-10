#include <stdio.h>
#include <dirent.h>
#include <stdlib.h> // for the exit



int main(int argc, char **argv) // pointer to a pointer. Pointer pointer 
{
  char *dirname;
  int i;

    printf("There are %d command line argument(s):\n", argc);

    for (i = 0; i < argc; i++) {
        printf("   %s\n", argv[i]);
    }
  if ( argc > 2)
  {
    printf("ERROR: Too many arguments :(\n");
    exit(128); // invalid arguments 
  }
  else if ( argc == 1)
  {
  dirname = '.';
  }
  else
  {
    dirname = argv[1];
  }
  DIR *d; 
    struct dirent *dir;
    d = opendir(dirname);
    if (d) {
      while ((dir = readdir(d)) != NULL) {
         if (dir->d_type == DT_REG) // DT_REG == A regular file
    {
      printf("%s\n", dir->d_name); 
    }
      }
      closedir(d);
    }
    else{
      printf("Error %p", d);
      exit(1);
    }
    
    return 0;
}
