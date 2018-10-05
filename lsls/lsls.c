#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
    // Parse command line

    // Open directory
    
    DIR *dir = opendir(".");
    struct dirent *dp;

    if (dir == NULL) {
        perror ("Cannot open .");
        return 0;
    }

    // Repeatly read and print entries

    while ((dp = readdir (dir)) != NULL) {
        printf("%s\n", dp->d_name);
    }

    // Close directory

    return 0;
}