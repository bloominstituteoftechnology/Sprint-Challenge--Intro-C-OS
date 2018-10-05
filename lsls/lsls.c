#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
    // Parse command line

    int i;
    char *args;

    // argc is the number of arguments entered into command line
    // **argv is the pointer to the address of the argument string?
    // printf("There are %d command line argument(s):\n", argc);
    // printf("argv is : %d", argv);

    for (i = 0; i < argc; i++) {
        // printf("   %s\n", argv[i]);
        args = argv[i];

    }

    // return 0;


    // Open directory

    DIR *dir = opendir(args);
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

    closedir(dir);
    // printf("Directory closed.");

    return 0;
}