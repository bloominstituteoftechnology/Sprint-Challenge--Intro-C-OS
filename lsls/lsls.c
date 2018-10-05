#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
    // Parse command line
    int i;

    printf("There are %d command line argument(s):\n", argc);

    for (i = 0; i < argc; i++) {
        printf("   %s\n", argv[i]);
    }

    // Open directory
  DIR * d;
    struct dirent * dir_entry;  // Pointer for directory entry
    if (argc == 1) {
        d = opendir(".");   // opendir() returns a pointer of DIR type
    } else {
        d = opendir(argv[1]);
    }

    if (d == NULL) //opendir returns NULL if couldn't open directory
    {
        printf ("This %s directory cannot be opened.\n", argv[1]);
        exit(1);
    }
    // Repeatly read and print entries.
    //returns a pointer to a structure representing the directory entry at the current position
    dir_entry = readdir(d);

    while (dir_entry != NULL) {
      printf ("%s\n", dir_entry->d_name);
      dir_entry = readdir(d);
    }

    // Close directory
    closedir(d);

    return 0;
}
