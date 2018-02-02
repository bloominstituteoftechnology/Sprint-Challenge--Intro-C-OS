#include <stdio.h>
#include <dirent.h>

 int main(int argc, char **argv)
  {
   // Parse command line
   struct dirent *dirEntry;
   DIR *dirName;
   char x[2] = ".";
   // Open directory
   if (argc < 2) {
     dirName = opendir (x);
   }
   else {
     dirName = opendir (argv[1]);
       if (dirName == NULL) {
         printf ("Cant open '%s'\n", argv[1]);
         return 1;
     }
   }
   // Repeatly read and print entries
   while ((dirEntry = readdir(dirName)) != NULL) {
     printf ("* %s\n", dirEntry->d_name);
   }
   closedir (dirName);

    return 0;
  }
