#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>
/**
 * Main
 */
int main(int argc, char **argv) {

  DIR *dir;
  struct dirent *line;
  struct stat buf;

  dir = opendir(argv[1]);

  if (dir != NULL) {
    while ((line = readdir(dir)) != NULL) {
    stat(line->d_name, &buf);
    if (stat(line->d_name, &buf) == -1) {
        continue;
    }
      printf("  %lld  %s\n", buf.st_size, line->d_name);
    }
    closedir(dir);
  }
  else {
    perror("error");
  }

  return 0;
}