#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  int i;

  printf("There are %d command line argument(s):\n", argc);

  for (i = 0; i < argc; i++)
  {
    printf("   %s\n", argv[i]);
  }
// -------------------------------------------
  DIR *dir;
struct dirent *ent;
 if ((dir = opendir ("c:\\src\\")) == NULL) {    // catch error; exit
        fprintf(stderr, "opendir failed\n");
        exit(1);
} else if ((dir = opendir ("c:\\src\\")) != NULL) {
  /* print all the files and directories within directory */
  while ((ent = readdir (dir)) != NULL) {
    printf ("%s\n", ent->d_name);
  }
  closedir (dir);
} else {
  /* could not open directory */
  perror ("could not open directory");
}
return 0;
}

//   // Open directory
//   DIR *opendir(char *path);
//   // Repeatly read and print entries
//   struct dirent *readdir(DIR * d){
//     ino_t  d_ino       // file serial number
//   char   d_name[]    // file name, a string
//   }
//   struct dirent *ent;

// // ... some of your code ...

// ent = readdir(d);

// printf("%s\n", ent->d_name);
//   // Close directory
//   closedir(DIR * d);
//   return 0;
