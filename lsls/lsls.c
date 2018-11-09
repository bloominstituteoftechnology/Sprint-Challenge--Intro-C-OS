#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/types.h>
#include<string.h>
#include<sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
    DIR *returned;
    struct dirent *fileStruct;

    char path[10];
    if(argc == 1){
      *path = *argv[0];
      returned = opendir(path);
    } else {
      returned = opendir(argv[1]);
    }

    
    if(returned == NULL) {
        printf("You have entered an incorrect file path.\n");
        exit(1);
    }

    struct stat buf;

    while((fileStruct = readdir(returned)) != NULL) {
        printf("%s\n", fileStruct->d_name);

        char command[50] = "./lsls/";
        char *pathnames = fileStruct->d_name;
        strcat(command, pathnames);

        stat(command, &buf);
        printf("file size is %ld\n", buf.st_size);
    }





    closedir(returned);

  return 0;
}