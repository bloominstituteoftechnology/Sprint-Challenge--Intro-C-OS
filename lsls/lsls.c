#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
    DIR *dir;
    struct dirent *entry;

    // Parse command line
    int i;

    printf("There are %d command line argument(s):\n", argc);

    for (i = 0; i < argc; i++) {
        printf("   %s\n", argv[i]);
    }

    // Open directory
    if (argc == 1) {
        dir = opendir(".");
    } else {
        dir = opendir(argv[1]);
    }

    if (dir == NULL) {
        printf ("%s can't be opened.\n", argv[1]);
        exit(1);
    }
    // Repeatly read and print entries
    entry = readdir(dir);

    while (entry != NULL) {
      printf ("%s\n", entry->d_name);
      entry = readdir(dir);
    }

    // Close directory
    closedir(dir);

    return 0;
}