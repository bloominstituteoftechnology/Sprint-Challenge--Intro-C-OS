#include <stdio.h>  // for printf
#include <dirent.h> // for directory entries
#include <stdlib.h> // for exit()

/**
 * Main
 */

// after video solution

// argc stands for "argument count"; (http://crasseux.com/books/ctutorial/argc-and-argv.html)
// -  contains the number of arguments passed to the program.
// argv stands for "argument vector". (Vector - one dimensional array)
// - argv = one-dimensional array of string.  Each string is one of the arguments that was passed to the program.
// this command line: gcc -o myprog myprog.c =>
// argc =  4
// argv[0] = gcc   // is the name by which the program is called => there will always be at least one argument to a program
// argv[1] = -o
// argv[2] = myprog
// argv[3] = myprog.c

int main(int argc, char **argv) // accepts any number of command-line arguments
{
    printf("This program is called with %s\n", argv[0]);
    printf("There are %d command line argument(s):\n", argc);

    for (int i = 0; i < argc; i++)
    {
        printf("   %s\n", argv[i]);
    }
    // for testing run this: gcc lsls.c
    // then:  ./a.out first second third fourth

    // Parse command line
    char *dirname;
    if (argc == 1)
    {
        printf("No arguments were passed.\n");
        dirname = ".";
    }
    else if (argc == 2)
    {
        dirname = argv[1];
    }
    else
    {
        fprintf(stderr, "error with a name path\n");
        exit(1);
    }
    // Open directory
    // DIR - a type representing a directory stream - an ordered sequence of all the directory entries in a particular directory.
    // - defines the structure dirent which includes the following:
    // struct dirent {
    //   ino_t  d_ino       // file serial number
    //   char   d_name[]    // file name, a string
    // };

    DIR *d = opendir(dirname); // if success - pointer to an object of type DIR
    //  The opendir() function opens a directory stream corresponding to the directory named by the dirname argument.
    // opendir() - opens a directory so that it can be read with readdir()

    if (d == NULL) // if there is an error ( and errno is set to indicate the error )
    {
        fprintf(stderr, "Directory does not exist\n");
        exit(2);
    }

    // Repeatly read and print entries
    struct dirent *ent; // 'struct dirent' included in <dirent.h>
    // Directory entries represent files that can be removed or added asynchronously to the operation of readdir()
    // readdir() - returns a pointer to a structure representing the directory entry  at the current position in the directory stream specified by the argument dirp, and positions the directory stream at the next entry. It returns a null pointer upon reaching the end of the directory stream.
    while ((ent = readdir(d)) != NULL) // as long as there are directory entries - they are assigned to entry
    {
        printf("%s\n", ent->d_name);
    }
    // Close directory
    //  closedir() - closes the directory stream referred to by the argument dirp.
    closedir(d);
    return 0;
}
