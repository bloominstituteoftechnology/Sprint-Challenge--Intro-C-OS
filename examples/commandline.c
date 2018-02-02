// gcc -Wall -Wextra -o commandline commandline.c
 
#include <stdio.h>
#include <dirent.h>

int main(int argc, char **argv)
{
    struct dirent *pDirent;
    DIR *pDir;

    pDir = opendir ((argc == 1) ? "." : argv[1]);
    if (pDir == NULL) {
        printf("Can not open this dir '%s'\n", argv);
        return 1;
    }

    while ((pDirent = readdir(pDir)) != NULL) {
        printf ("%s\n", pDirent->d_name);
    }
    closedir(pDir);
    return 0;
}