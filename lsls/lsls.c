#include <stdio.h>
#include <dirent.h>

// /**
//  * Main
//  */
// int main(int argc, char **argv)
// {
//   // Parse command line

//   // Open directory

//   // Repeatly read and print entries

//   // Close directory

//   return 0;
// }

// for ls program: https://www.geeksforgeeks.org/c-program-list-files-sub-directories-directory/ 
// for readdir: http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html 

int main(void)
{
    struct dirent *de; // pointer for directory entry

    //opendir() returns a point of DIR type.
    DIR *dr = opendir(".");

    if (dr == NULL) // opendir returns NULL if it can't open direcory
    {
        printf("Sorry, you can't open the current directory");
        return 0;
    }
    while ((de = readdir(dr)) != NULL)
        printf("%s\n", de -> d_name);
    
    closedir(dr);
    return 0;

}