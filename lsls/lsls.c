#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

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
    directory = opendir(".");
    if (directory == NULL) {
        printf("Cannot open directory '%s'\n", argv[1]);
        return 0;
    }

  // Repeatly read and print entries
  struct stat buf;
  printf("file size is %lld\n", buf.st_size);

  while ((pDirent = readdir(directory)) != NULL) {
        stat(*argv, &buf);
        printf("[%10lld] [%s]\n", buf.st_size, pDirent->d_name);
    }


  // Close directory
        closedir(directory);

  return 0;
}