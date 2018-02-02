#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  if (argc == 1) { // we have no arguments to parse!
    DIR *d = opendir(".");
    struct dirent *entry;
    struct stat buf;

    if (d == NULL) {
      perror("opendir() error");
    } else {
      printf("contents of: %s\n", ".");
      while((entry = readdir(d)) != NULL) {
        char *str = malloc(strlen(".") + strlen("/") + strlen(entry->d_name));
        sprintf(str, "%s%s%s", ".", "/", entry->d_name);
        stat(str, &buf);
        if ((buf.st_mode & S_IFDIR) != 0) { // it's a directory...
          printf("  %10s  %s\n", "<DIR>", entry->d_name);
        // } else if ((buf.st_mode & S_IFREG) != 0) { // it's a file...
        } else {
          printf("  %10ld  %s\n", buf.st_size, entry->d_name);
        }
        free(str);
      }
    }
  // Close directory
    closedir(d);
    return 0;
  }

  // else we have argument(s) to parse
  int i;
  // Open directory
  for (i = 1; i < argc; i++) {
  // Repeatly read and print entries
    DIR *d = opendir(argv[i]);
    struct dirent *entry;
    struct stat buf;

    if (d == NULL) {
      perror("opendir() error");
    } else {
      printf("contents of: %s\n", argv[i]);
      while((entry = readdir(d)) != NULL) {

        char *str = malloc(strlen(argv[i]) + strlen("/") + strlen(entry->d_name));
        sprintf(str, "%s%s%s", argv[i], "/", entry->d_name);
        stat(str, &buf);
        if ((buf.st_mode & S_IFDIR) != 0) { // it's a directory...
          printf("  %10s  %s\n", "<DIR>", entry->d_name);
        // } else if ((buf.st_mode & S_IFREG) != 0) { // it's a file...
        } else {
          printf("  %10ld  %s\n", buf.st_size, entry->d_name);
        }
        free(str);
      }
    }
  // Close directory
    closedir(d);
  }

  return 0;
}