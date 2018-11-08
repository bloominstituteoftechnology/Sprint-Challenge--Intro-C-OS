#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *pDirent;
  struct stat buf;
  DIR *pDir;

  // Parse command line
  char *directory = argv[1] ? argv[1] : "./";
  size_t directory_length = strlen(directory);
  char *path = malloc(directory_length + 1 + NAME_MAX);
  strcpy(path, directory);
  path[directory_length] = '/';
  // Open directory
  pDir = opendir(directory);

  if (pDir == NULL) {
    printf("Cannot open directory %s.\n", directory);
    return 1;
  }

  // Repeatly read and print entries
  while ((pDirent = readdir(pDir)) != NULL) {
    strcpy(path + directory_length + 1, pDirent->d_name);
    stat(path, &buf);
    if ((buf.st_mode & S_IFDIR) != 0) {
      printf("     <DIR> %s\n", pDirent->d_name);
    } else if ((buf.st_mode & S_IFREG) != 0) {
      printf("%10lld bytes %s\n", buf.st_size, pDirent->d_name);
    }
  }
  // Close directory
  closedir(pDir);

  return 0;
}