// http://www.codingalpha.com/list-all-contents-of-directory-c-program/
// for ls program: https://www.geeksforgeeks.org/c-program-list-files-sub-directories-directory/ 
// for readdir: http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html 

#include <stdio.h>
#include <dirent.h>

// /**
//  * Main
//  */


int main(int argc, char **argv)
{
    DIR *ptr;
    struct dirent *directory;

    //Open Directory
    if (argc == 1){
      ptr = opendir(".");
    }
    else{
      ptr = opendir(argv[1]);
    }

    if (ptr == NULL){
      printf("Cannot open %s\n", argv[1]);
      return 1;
    }

    //repeatedly read and print entries
    while ((directory = readdir(ptr)) != NULL){
      printf("%s\n", directory -> d_name);
    }

    //close directory
    closedir(ptr);
  return 0;
}


// int main(void)
// {
//     struct dirent *de; // pointer for directory entry

//     //opendir() returns a point of DIR type.
//     DIR *dr = opendir(".");

//     if (dr == NULL) // opendir returns NULL if it can't open direcory
//     {
//         printf("Sorry, you can't open the current directory");
//         return 0;
//     }
//     while ((de = readdir(dr)) != NULL)
//         printf("%s\n", de -> d_name);
    
//     closedir(dr);
//     return 0;
// }

// // another verion try entering / at the prompt
// int main()
// {

//       char directory_name[10];
//       DIR *ptr;
//       struct dirent *directory;

//       // Parse Command Line
//       printf("Enter Directory Name:\t");
//       scanf("%s", directory_name);
      
//       // Open Directory
//       ptr = opendir(directory_name);
//       printf("\nDirectory %s\n", directory_name);

//       //repeatedly read and print entries
//       while((directory = readdir(ptr)) != NULL)
//       {
//             printf("%s\n", directory->d_name);
//       }

//       //close directory
//       closedir(ptr);

//       return 0;
// }

