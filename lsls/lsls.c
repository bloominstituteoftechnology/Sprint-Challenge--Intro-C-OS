#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *dp;
  char *file_name;
  struct stat buf;

  if(argc != 2){
    fprintf(stderr, "\nUsage: ./lsls <PATH>\n\n");
    exit(1);
  }

  dir = opendir(argv[1]);

  while((dp=readdir(dir)) != NULL){
    stat(dp->d_name, &buf);
    if((buf.st_mode&S_IFDIR) != 0){
      printf("     <DIR> %s\n", dp->d_name);
    }else{
      printf("%10lld %s\n", buf.st_size, dp->d_name);
    }
  }

  closedir(dir);
  return 0;
}
