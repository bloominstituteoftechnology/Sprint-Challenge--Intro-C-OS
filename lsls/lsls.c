#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <limits.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *dp;
  char *file_name;
  struct stat buf;
  char *list_path;

  if(argc == 1){
    list_path = ".";
  }else if(argc == 2){
    list_path = argv[1];
  }else{
    fprintf(stderr, "\nUsage: ./lsls <PATH>\n\n");
    exit(1);
  }

  dir = opendir(list_path);

  while((dp=readdir(dir)) != NULL){
    char path[PATH_MAX];
    snprintf(path, sizeof(path), "%s/%s", list_path, dp->d_name);
    if(stat(path, &buf)==0){
      if((buf.st_mode&S_IFDIR) != 0){
        printf("     <DIR> %s\n", dp->d_name);
      }else{
        printf("%10lld %s\n", buf.st_size, dp->d_name);
      }
    }
  }

  closedir(dir);
  return 0;
}
