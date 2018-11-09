#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

// #define MAX_CMD_LEN 9824
// #define MAX_CMD_ARGS 128

/**
 * Main
 */
  // steps
  // Parse command line
  
  // Open directory
  
  // Repeatly read and print entries

  // Close directory



int main(int argc, char **argv)
// int main(void)
{
  char *dirname;
  // char commandLine[MAX_CMD_LEN];

  if (argc == 1){
    dirname = ".";
  }else if (argc == 2) {
    dirname = argv[1];
  }else{
    fprintf(stderr, "error: lsls [dirname]\n");
    return 1;
  }


  // while (printf("> ", fgets(commandLine, sizeof commandLine, stdin)) != NULL){
    
    DIR *d = opendir(dirname);

    if (d == NULL ) {
      perror("lsls");
      return 1;
    }

    struct dirent *de;
    char fullpath[9812];


    while((de = readdir(d)) != NULL ){
      sprintf(fullpath, "%s/%s", dirname, de->d_name);
      printf("%s\n", de->d_name);
    }

    int closedir(DIR *de);

  // }
  return 0;


}
