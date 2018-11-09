#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
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
        struct stat buf;
        char subdir[1028] = "";
        strcat(subdir, argv[1]);
        if (argv[1][strlen(argv[1])-1]!='/') {
          strcat(subdir,"/");
        }
        strcat(subdir, ent->d_name);
        strcat(subdir,"\0");
        stat(subdir, &buf);
        if ((buf.st_mode & S_IFDIR)!=0) {
          printf("<DIR> %s\n",ent->d_name);
        } else {
          printf("%lld %s\n", buf.st_size,ent->d_name);
        }
    }
    closedir(strm);
    } else {
      printf("Program has error.");
      exit(-1);
  }
  } else if (argc==1) {
    if ((strm=opendir("./"))!=NULL) {
      while ((ent=readdir(strm))!=NULL){
        struct stat buf;
        char subdir[1028] = "";
        strcat(subdir, "./");
        strcat(subdir, ent->d_name);
        strcat(subdir,"\0");
        stat(subdir, &buf);
        if ((buf.st_mode & S_IFDIR)!=0) {
          printf("<DIR> %s\n",ent->d_name);
        } else {
          printf("%lld %s\n", buf.st_size,ent->d_name);
        }
    }
    closedir(strm);
    } else {
      printf("Program has error.");
      exit(-1);
    }
  }
  return 0;
}