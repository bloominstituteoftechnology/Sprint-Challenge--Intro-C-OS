#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  
  struct dirent *ent;
  DIR *strm;
  if (argc==2) {
    if ((strm=opendir(argv[1]))!=NULL) {
      while ((ent=readdir(strm))!=NULL){
      printf("%s\n", ent->d_name);
    }
    closedir(strm);
    } else {
    printf("Program has error.");
    exit(-1);
  }
  } else if ((strm=opendir("."))!=NULL) {
    while ((ent=readdir(strm))!=NULL){
      printf("%s\n", ent->d_name);
    }
    closedir(strm);
  } else {
    printf("Program has error.");
    exit(-1);
  }
  
 

  return 0;
}