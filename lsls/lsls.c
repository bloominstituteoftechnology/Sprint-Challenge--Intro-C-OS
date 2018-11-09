#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *pDirent;
  DIR *pDir;
  struct stat sizebuf;
  // Parse command line
  if (argc < 2) {
    printf("Usage: ./lsls <directory>");
    return 1;
  }

  // Open directory
  pDir = opendir(argv[1]);
  if (pDir == NULL) {
    printf("Cannot open directory '%s'\n", argv[1]);
    return 1;
  }

  // Repeatly read and print entries

  while ((pDirent = readdir(pDir)) != NULL) {
    stat(pDirent->d_name, &sizebuf);
    printf("  %10ld  %s\n", sizebuf.st_size, pDirent->d_name);
  }

  // Close directory
  closedir(pDir);
  return 0;
}