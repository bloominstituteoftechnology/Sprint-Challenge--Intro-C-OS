#include <stdio.h>
#include <dirent.h>
#include <errno.h>
/**
Pull Request
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
    // for (int i = 0; i < argc; i++) {
  // printf("%s\n", argv[i]);
    // }
    // printf("%s\n", name)
  char *dirname;
   if (argc == 1) {
     dirname = ".";
   } else if (argc == 2) {
     dirname = argv[1];
   }
  // Open directory 
    DIR *directory = opendir(dirname); 
    // struct dirent *file; {
    //   char d_name[256];
    //   __ino_t d_ino; 
    // };
    struct dirent *file; 
    if (directory != NULL) {
        while((file = readdir(directory)) != NULL)
        {
  // Repeatly read and print entries
          printf("%s\n", file->d_name);
          // char fileName = file->d_name;
          // printf(fileName);
        }
        
          // Close directory
          closedir(directory); 
  }else {
    perror("lsls");
    return 1;
  }
        // 
      return 0;
}
  
    /* 
 
    */

