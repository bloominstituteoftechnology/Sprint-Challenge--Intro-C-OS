#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
    int i;
    struct dirent *pDirent;
    DIR *pDir;

    // printf("There are %d command line argument(s):\n", argc);

    // for (i = 0; i < argc; i++) {
    //     printf("   %s\n", argv[i]);
    // }

    if (argc < 2) {
        printf("Usage: ./lsls <directory>\n");
    return 1;
    }

    pDir = opendir(argv[1]);
    if (pDir == NULL){
        printf("Cannot open directory %s\n", argv[1]);
        return 0;
    }
    while ((pDirent = readdir(pDir)) != NULL){
        printf("%s\n", pDirent -> d_name);
    }
    closedir(pDir);
    
    return 0;

  return 0;
}