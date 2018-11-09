#include <stdio.h>
#include <dirent.h>

/**
Pull Request
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
    //   int i;
    //   file_name[256]
    // char *file_name = malloc((**argv+1) * sizeof(char));

    
    for (int i = 0; i < argc; i++) {
        // printf("%s\n", argv[i]);

    }

    // printf("%s\n", name)

   
  // Open directory 
    DIR *directory = opendir(argv[1]); 
    struct dirent  {
      char d_name[256];
      ino_t d_ino; //idk if that's legit
    };

    if (directory != ".") {
        while ((file =readdir(directory)) != NULL) {
          printf("%s\n", file->d_name);
          char fileName = file->d_name;
          printf(fileName);
          closedir(directory);
        }
        
        // 
      }
      return 0;
    }
    
    /* 
 
    */

  // Repeatly read and print entries
  // Close directory
