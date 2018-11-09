#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *de;  // Pointer for directory entry 

  // parsing from the command line
  char* parse = argv[1];
  // if (argc > 1) {
  //   char* parse = argv[1];
  // } else char* parse = ".";
  
  
  // opendir() returns a pointer of DIR type.  
  DIR *dr = opendir(parse); 
  // if (argc < 2) {
  //   printf("argc is less than 2\n");
  //   DIR *dr = opendir(".");
  // }
  // else if (argc >= 2) {
  //   printf("argc is 2 or greater\n");
  //   DIR *dr = opendir(parse);
  // }

  if (dr == NULL)  // opendir returns NULL if couldn't open directory 
  { 
      printf("Could not open directory %s\n", parse ); 
      return 0; 
  } 
  struct stat buf;

  while ((de = readdir(dr)) != NULL) 
          // stat(de->d_name, &buf);
          // printf("%10ld %s\n", buf.st_size, de->d_name); 
          printf("%s\n", de->d_name);

  // printf("%s\n", parse);
  

  // stat("./lsls.c", &buf);

  // printf("file size is %lld\n", buf.st_size);

  printf("---end of directory--- \n");
  closedir(dr);  

  return 0;
}