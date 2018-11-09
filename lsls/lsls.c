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
  char* parse; // = argv[1];
  if (argc == 1) {
    parse = ".";
  } else parse = argv[1];
  
  
  // opendir() returns a pointer of DIR type.  
  DIR *dr = opendir(parse); 

  if (dr == NULL)  // opendir returns NULL if couldn't open directory 
  { 
      printf("Could not open directory %s\n", parse ); 
      return 0; 
  } 

  char path[8000];
  struct stat buf;

  while ((de = readdir(dr)) != NULL) { 
          // sprintf(path, "%s/%s\n", parse, de->d_name);
          stat(de->d_name, &buf);
          printf("%10ld %s\n", buf.st_size, de->d_name); 
          // printf("%s\n", de->d_name);
          // printf("%s\n", path);
  }
  // printf("%s\n", parse);
  

  // stat("./lsls.c", &buf);

  // printf("file size is %lld\n", buf.st_size);

  printf("---end of directory--- \n");
  closedir(dr);  

  return 0;
}