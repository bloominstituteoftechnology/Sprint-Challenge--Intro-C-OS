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
  struct dirent *entry;
  struct stat buf;

  if (argc == 1) {
    dir = opendir(".");
  } else {
    while(argv[1][0] == '/') {
      argv[1]++;
    }
    dir = opendir(argv[1]);
  }

  if (dir == NULL) {
    printf("There seems to be an error opening the directory\n");
    exit(0);
  }

  while((entry = readdir(dir)) != NULL) {
    stat(entry->d_name, &buf);
    if ((buf.st_mode & S_IFDIR) > 0) {
      printf("<DIR> %s\n", entry->d_name);
    } else {
      printf("%lld %s\n", buf.st_size, entry->d_name);
    }
  }

  closedir(dir);

  return 0;
}