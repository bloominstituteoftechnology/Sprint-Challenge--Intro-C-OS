#include <stdio.h>
#include <dirent.h>

#include <stdlib.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  // int i;
  
  

  //   printf("There are %d command line argument(s):\n", argc);

  //   for (i = 0; i < argc; i++) {
  //       printf("   %s\n", argv[i]);
  //       // printf( "  argv[%d]   %s\n", count, argv[count] );
  //   }

char *path[1];
if (argc == 1){*path = ".";}else{*path = argv[1];}
  // Open directory
DIR *dir;
// DIR *opendir(char *path);
struct dirent *ent;

dir = opendir(*path);
ent = readdir(dir);



if (dir == NULL) {
        perror ("Cannot open .");
        exit (1);
}
  // Repeatly read and print entries
while ((ent = readdir (dir)) != NULL) {
  printf(" %s\n", ent->d_name);
}
    
 
  // Close directory
closedir(dir);

  return 0;
}