#include <dirent.h> 
#include <stdio.h> 
#include <sys/stat.h>
#include <string.h>

int main(int argc, char **argv) {
  //declare variables
  DIR *d;
  struct dirent *ent;
  struct stat buf;
  char *path;
  path = argv[1];

  //open dir
  d = opendir(path);

  //loop through directory contents
  if (d) {
    while ((ent = readdir(d)) != NULL) {
      char* fullpath = malloc(strlen(path) + strlen(ent->d_name) + 10);
      strcat(fullpath, path);
      strcat(fullpath, "/");
      strcat(fullpath, ent->d_name);
      // printf("full path name is %s\n", fullpath);
      stat(fullpath, &buf);
      // printf("file size is %lld\n", buf.st_size);
      printf("%lld%s%s\n", buf.st_size, " ", ent->d_name);

      free(fullpath);
      
    }
    closedir(d);
  }
  return 0;
}