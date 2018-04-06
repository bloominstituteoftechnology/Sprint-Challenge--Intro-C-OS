#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int printDir(char *path) {
  
  struct dirent *ent;
  DIR *d;
  d = opendir(path);
  
  if (d) {
    while ((ent = readdir(d)) != NULL) {
      printf("%s\n", ent->d_name);
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
