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

    printf("There are %d directories:\n", argc);

    for (i = 0; i < argc; i++) {
        printf("   %s\n", argv[i]);
    }

  // Open directory
    struct dirent *de;
    struct stat st;
    DIR *dr = opendir(".");
    // long int size=0;
 
    if (dr == NULL)  // opendir returns NULL if couldn't open directory
    {
        printf("Could not open current directory" );
        return 0;
    }
  // Repeatly read and print entries
    struct dirent {
      ino_t  d_ino;       // file serial number
      char   d_name[];    // file name, a string
    };

    while ((de = readdir(dr)) != NULL)
            printf("%s %10lld\n", de->d_name, &st);
  // Close directory
    closedir(dr);
  return 0;
}
