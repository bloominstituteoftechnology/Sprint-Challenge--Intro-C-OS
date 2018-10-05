#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
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
    printf("\033[1;31merror\033[0m\033[1m: no such file or directory\033[0m\n");
    return 0;
  }
  // Repeatly read and print entries
  struct dirent *id;

  while ((id = readdir(d)) != NULL) {
    struct stat buf;
    char fullpath[8192];
    sprintf(fullpath, "%s/%s", *path, id->d_name);

    if (stat(fullpath, &buf) == -1) {
      perror("stat");
    }

    if (buf.st_mode & S_IFREG) {
      printf("%-5lld  %s\n", buf.st_size, id->d_name);

    } else if (buf.st_mode & S_IFDIR) {

      printf("%-5s  %s\n", "<DIR>", id->d_name);
    } else {
      printf("%-5s  %s\n", "", id->d_name);
    }
  }
  // Close directory
  closedir(d);
  return 0;
}