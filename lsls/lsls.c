#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
// Parse command line  
    struct dirent *entries;
    DIR *dir;
// Open directory
    if (argc == 1) {
        dir = opendir(".");
    }
    else {
        dir = opendir(argv[1]);
    }  
// Repeatly read and print entries
    entries = readdir(dir);
    while (entries != NULL) {
        printf("%s\n", entries->d_name);
        entries = readdir(dir);
    }
// Close directory
    closedir(dir);
    return 0;
}