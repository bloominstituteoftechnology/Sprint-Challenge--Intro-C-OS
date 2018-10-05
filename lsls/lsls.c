#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
/**
 * Main
 */

 int main(int argc, char **argv)
 {
   //initial error checking, only want one additional argument.

   if(argc > 2){
     printf("%s\n", "Invalid amount of arguments");
     return EXIT_FAILURE;
   }

   // Making a buffer to hold the directory to print

   char direcLocation[100];

   // Base directory, I want to start at my Desktop

   strcat(direcLocation, "/mnt/c/Users/Borg/Desktop/");

   // if argument is provided, arc == 2, so get the supplied argument

   if (argc == 2){
     strcat(direcLocation, argv[1]);
   }

   // open stream to view directory, second is to iterate through items within directory
   DIR *dirp;
   struct dirent *direntp;

   // give the stream a location with the string made in line 24 or 29
   dirp = opendir( direcLocation );

   // if this == null, the directory wasn't found, return error
   if( dirp == NULL ) {
       perror( direcLocation );
   } else {
   // directory was found, continous loop invoked
       for(;;) {
   //checks for a value, if this == null, we reached the end of the queue so loop will break
           direntp = readdir( dirp );
           if( direntp == NULL ) break;
   //we don't have null so it is safe to print, access d_name pointer to print current directory iteration
           printf( "%s\n", direntp->d_name );
       }
   //closing the directory stream
       closedir( dirp );
   }

   //providing a return value
     return EXIT_SUCCESS;
 }
