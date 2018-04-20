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
    stat(path, &buf);

    if((buf.st_mode & S_IFDIR) != 0) {  // Testing if its a directory
      printf("     <DIR>    %s\n", entry->d_name);

    } else if ((buf.st_mode & S_IFREG) != 0) {  // Testing if its a file
      printf("%10lld    %s\n", buf.st_size, entry->d_name);

    } else {
      printf("              %s\n", entry->d_name);
    }
    entry = readdir(d);
  }
  closedir(d);
}

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *d;

  if(argc > 2) {
    perror("Too many arguments supplied");
    return 1;
  }
  if(argc > 1) {
    d = opendir(argv[1]);

    if(d == NULL) {
      perror("Directory doesnt exist");
      return 1;
    } else {
      printDirs(d, argv[1]);
    }
  } else {
    d = opendir(".");

    if(d == NULL) {
      perror("Directory doesnt exist");
      return 1;
    } else {
      printDirs(d, ".");
    }
  }

  return 0;
}