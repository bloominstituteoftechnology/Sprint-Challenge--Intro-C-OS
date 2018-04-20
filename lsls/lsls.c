#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
 if (argc == 1) {
   struct dirent *directoryent;
   DIR *df = opendir(".");   // Open directory
   while((directoryent = readdir(df)) != NULL) {
     printf("%s\n%d", directoryent->d_name, directoryent->d_type);
   }
   closedir(df);  // Close directory
 }
 return 0;
}
      // int dirp = opendir(".");
      // while (dirp) {
      //   int errno = 0;
      //   if ((readdir(dirp)) != NULL) {

      //   }
      // }
      // DIR *opendir(const char *dirent);

          // readdir(argc);
          //   for( i = 0; i < argc; i++ ) 
          //   printf_s( " argc[%d]   %s\n", argc ); // Repeatly read and print entries