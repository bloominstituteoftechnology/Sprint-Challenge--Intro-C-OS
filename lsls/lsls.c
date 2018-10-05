#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

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

    for (i = 0; i < argc; i++) {
        args = argv[i];
    }

    // Open directory

    DIR *dir = opendir(args);
    struct dirent *dp;
    struct stat buf;
    stat(args, &buf);

    if (dir == NULL) {
        perror ("Cannot open .");
        return 0;
    }

    // Repeatly read and print entries

    while ((dp = readdir (dir)) != NULL) {
        printf("%10lld  ", buf.st_size);
        printf("%s\n", dp->d_name);
    }

    // Close directory

    closedir(dir);

    return 0;
}