#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  int i;
  // Parse command line
  DIR *dir;
  struct dirent *ent;
  struct stat buf;
  if (argc < 2) {
    if ((dir = opendir(".")) == NULL) {
      perror ("Error opening .");
      exit(1);
    }
  } else {
    if ((dir = opendir(argv[0])) == NULL) {
      perror ("Error opening .");
      exit(2);
    }
  }
  // Open directory
  opendir("   %s\n");
  printf("There are %d command line argument(s):\n", argc);

  for (i=0; i< argc; i++) {
    printf("  %s\n", argv[i]);
  }
  printf("\nCurrent directory: \n\n");
  // Repeatly read and print entries
  while((ent = readdir(dir)) != NULL) {
    stat("./", &buf);
    printf("%10lld %s\n", buf.st_mode, ent->d_name);
    // printf("%s %d\n", ent->d_name, ent->d_ino);
  }
  // Close directory
  closedir(dir);
  return 0;
}