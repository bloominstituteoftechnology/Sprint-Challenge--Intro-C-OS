#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

// Helper function because this was becoming a mess inside main()
void print_dirs(DIR *d, char dir[]) {
  struct dirent *ent;
  struct stat buf;
  char path[256];
  ent = readdir(d);

  while ((ent = readdir(d)) != NULL) {
    sprintf(path, "%s/%s", dir, ent->d_name);
    stat(path, &buf);

    if ((buf.st_mode & S_IFDIR) != 0) {
      printf("<DIR> %s\n", ent->d_name);
    } else if ((buf.st_mode & S_IFREG) != 0) {
      printf("%10ld %s\n", buf.st_size, ent->d_name);
    } else {
      printf("%s\n", ent->d_name);
    }
  }
  closedir(d);
}

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *d = opendir(argv[1] ? : ".");

  if (argc) { // avoids compiler warnings for unused var
    if (errno != 0) {
      printf("Error: %s\n", strerror(errno));
      exit(errno);
    } else {
      print_dirs(d, argv[1] ? : ".");
    }
    return 0;
  }
}