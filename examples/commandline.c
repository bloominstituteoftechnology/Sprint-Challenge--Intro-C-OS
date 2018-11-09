/**
 * Try running with various command line args:
 *
 * ./commandline hello world
 * ./commandline this is a test
 * ./commandline
 */

#include <stdio.h>
#include <dirent.h>

#define MAX_COMMANDLINE_LEN 8192
#define MAX_COMMANDLINE_ARGS 128


int main(int argc, char **argv)
{
    int i;
    struct dirent *pDirent;
    DIR *pDir;

    pDir = opendir(".");
    if (pDir == NULL){
        printf("Cannot open directory %s\n", argv[1]);
        return 0;
    }
    while ((pDirent = readdir(pDir)) != NULL){
        printf("%s\n", pDirent -> d_name);
    }
    closedir(pDir);
    

    // printf("There are %d command line argument(s):\n", argc);

    // for (i = 0; i < argc; i++) {
    //     printf("   %s\n", argv[i]);
    // }

    return 0;
}