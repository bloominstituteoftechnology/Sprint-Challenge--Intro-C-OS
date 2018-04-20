#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>

void printDirs(DIR *d, char dir[])
{
  struct dirent *entry;
  struct stat buf;
  char path[200];

  entry = readdir(d);
  while(entry != NULL) {
    sprintf(path, "%s/%s", dir, entry->d_name);
    // printf("test: %s\n", entry->d_name);
    stat(path, &buf);
    printf("%10lld    %s\n", buf.st_size, entry->d_name);
    entry = readdir(d);
  }
  closedir(d);
}

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  if(argc > 2) {
    // printf("%d\n%s\n%s", argc, argv[0], argv[1]);
    perror("Too many arguments supplied");
    return 1;
  }
  if(argc > 1) {
    DIR *d = opendir(argv[1]);
    if(d == NULL) {
      perror("Directory doesnt exist");
    } else {
      printDirs(d, argv[1]);
    }
  } else {
    DIR *d = opendir(".");
    if(d == NULL) {
      perror("Directory doesnt exist");
    } else {
      printDirs(d, ".");
    }
  }

  return 0;
}