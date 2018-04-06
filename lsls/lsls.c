#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  char *dir;
  struct dirent *ent;
  // Parse command line
  if (argc > 1) {
    dir = argv[1];
  } else {
    dir = ".";
  }
  // Open directory
  DIR *currentDir = opendir(dir);

  if (currentDir == NULL) {
    // printf("%s\n", );
    printf("%s directory does not exist.\n", argv[1]);
  }
  // Repeatly read and print entries
  while ((ent = readdir(currentDir)) != NULL) {
    struct stat buf;
    char size[1024];
    stat(ent->d_name, &buf);
    printf("%10lld %s\n", size, ent->d_name);
  }
  // Close directory
  closedir(currentDir);
  return 0;
}
