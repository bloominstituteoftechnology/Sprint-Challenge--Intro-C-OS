#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int printDir(char *path) {
  
  struct dirent *ent;
  struct stat buff;
  char file_path[128];

  DIR *d;
  d = opendir(path);
  
  if (d) {
    while ((ent = readdir(d)) != NULL) {
      
      strcat(file_path, path);
      strcat(file_path, "/");
      
      strcat(file_path, ent->d_name);
      stat(file_path, &buff);
      
      printf("%10lld, %s\n", buff.st_size, ent->d_name);
      
      file_path[0] = '\0';
      }
      closedir(d);
      } else {
        printf("%sThe directory in which you search was not found.\n", path);
        exit(1);
        }
        return 0;
}

int main(int argc, char **argv)
{
  
  char *path;
  
  if (argc == 1) {
    path = ".";
    printDir(path);
    } else {
      path = argv[1];
      printDir(path);
      }
      return 0;
} 
