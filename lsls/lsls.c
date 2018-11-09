#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
    int i;
    struct stat foldersize;
    struct dirent *pDirent;
    DIR *pDir;

    // printf("There are %d command line argument(s):\n", argc);

    // for (i = 0; i < argc; i++) {
    //     printf("   %s\n", argv[i]);
    // }

    if (argc < 2) {
        pDir = opendir(".");
    }
    else {
      pDir = opendir(argv[1]);
    }
  
    if (pDir == NULL){
      printf("Cannot open directory %s\n", argv[1]);
      return 0;
    }
    while ((pDirent = readdir(pDir)) != NULL){
      stat(pDirent -> d_name, &foldersize);
      if ((foldersize.st_mode & S_IFDIR) != 0){
        printf("<DIR> %s\n", pDirent -> d_name);
      }
      printf("  %10ld   %s\n", foldersize.st_size, pDirent -> d_name);
    }
    closedir(pDir);
    
    return 0;

  return 0;
}