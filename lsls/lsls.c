#include <stdio.h>
#include <dirent.h>

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

  // Open directory 
    DIR *directory = opendir(argv[1]); 
    // struct dirent *file; {
    //   char d_name[256];
    //   __ino_t d_ino; //idk if that's legit oooh i see. you don't need to do this, because this struct is declared in dirent.h
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
  }  
        // 
      return 0;
}
  
    /* 
 
    */

