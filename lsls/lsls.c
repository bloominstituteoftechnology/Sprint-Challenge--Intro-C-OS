#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  struct dirent *ent;
  struct stat buf;

  if(argc >= 2){
    for(int x = 0; x < argc; x++){
      if (x > 0) {

        printf("opening directory %s\n", argv[x]);
        DIR *d = opendir(argv[x]);
      
        if(d == 0){
          puts("error opening ");
          exit(1);
        }
        ent = readdir(d);
        while (ent){
          char *path = argv[x];
          char c[sizeof(argv[x]) + sizeof(ent->d_name)];
          strcpy(c, path);
          strcat(c, ent->d_name);

          int stats = stat(c, &buf);          
         
          if (stats >= 0){
            printf("%10lld %s\n", buf.st_size, ent->d_name);

          }else{
             printf("    %s\n", ent->d_name);
          }
          ent = readdir(d);
        }
        closedir(d);
      }
    }
    
  }else{
    DIR *d = opendir("./");
    printf("opening directory ./\n");
    
    if(d == 0){
      puts("error opening ");
      exit(1);
    }
    ent = readdir(d);
    while (ent){
      printf(" %s\n", ent->d_name);
      ent = readdir(d);
    }
    closedir(d);
  }
  return 0;
}