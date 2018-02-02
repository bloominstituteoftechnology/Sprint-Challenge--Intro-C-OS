#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
    int count;

    printf("There are %d command line argument(s):\n", argc);

    for (count = 0; count < argc; count++) {
        printf("  argv[%d]= `%s`\n", count, argv[count]);
    }

  // Open directory
    struct dirent *pDirent;
    DIR *directory;
    // if (argc < 2) {
    //     printf("Already in /lsls directory\n");
    //     return 0;
    // }
    directory = opendir(argv[1]);
    if (directory == NULL) {
        printf("Cannot open directory '%s'\n", argv[1]);
        return 0;
    }

  // Repeatly read and print entries
    while ((pDirent = readdir(directory)) != NULL) {
        printf("[%s]\n", pDirent->d_name);
    }

  // Close directory
        closedir(directory);

  return 0;
}