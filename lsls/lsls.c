#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *d;
  struct dirent *dir;
  char direc[20];
  char default_dir = '.';
  if(argv[1] != NULL){
    strcpy(direc, argv[1]);
  } else {
    printf("what?");
    strcpy(direc, default_dir);
  }
  d = opendir(direc);

  if(d){
    while((dir=readdir(d))!=NULL){
      printf(" >> %s\n", dir->d_name);
    }
    closedir(d);
  }
  return 0;
}