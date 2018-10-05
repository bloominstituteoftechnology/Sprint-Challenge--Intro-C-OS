#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *path[1];
  if (argc == 1) {
		*path = ".";
	} else {
    *path = argv[1];
  }
  // Open directory
  DIR *d = opendir(*path);
  // Checks for errors
  if (d == NULL) {
    printf("\033[31merror\033[37m: no such file or directory\n");
    return 0;
  }
  // Repeatly read and print entries
  struct dirent *id;
  struct stat buf;

  while ((id = readdir(d)) != NULL) {
    stat(id->d_name, &buf);
    if (stat(id->d_name, &buf) == -1) {
      perror("stat");
    }
    printf("%5lld   %s\n", buf.st_size, id->d_name);
  }
  // Close directory
  closedir(d);
  return 0;
}