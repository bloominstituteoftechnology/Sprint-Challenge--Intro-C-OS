#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *pDirent;
  struct stat buf;
  DIR *pDir;
  char *dir;

  // Parse command line
  if (argc < 2) {
    argv[argc++] = ".";
  }

  // Open directory
  pDir = opendir(argv[1]);
  if (pDir == NULL) {
    printf("Cannot open directory '%s'\n", argv[1]);
    return 1;
  }

  // Repeatly read and print entries
  while ((pDirent = readdir(pDir)) != NULL) {
    sprintf(dir, "%s/%s", argv[1], pDirent->d_name);
    stat(dir, &buf);
    if (buf.st_size == 0) {
      printf("%10s %s\n", "<DIR>", pDirent->d_name);
    } else {
      printf ("%10lld %s\n", buf.st_size, pDirent->d_name);
    }
  }
  // Close directory
  closedir(pDir);

  return 0;
}