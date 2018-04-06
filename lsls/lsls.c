#include <stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include <dirent.h>


/**
 * Main
 */
int main(int argc, char **argv)
  // Parse command line
  {
  int i;

  printf("There are %d command line argument(s):\n", argc);

  for (i = 0; i < argc; i++) {
    printf("   %s\n", argv[i]);
  }

  DIR *dp;
  struct dirent *sd;
  struct stat st;
  char buf[512];
  // Open directory
  dp = opendir(argv[1]);

  // Repeatly read and print entries
  while ((sd = readdir(dp)) != NULL) {
    stat(buf, &st);
    printf("%s\n",sd->d_name);
    printf("%lld\n", st.st_size);
  }
    // Close directory
  closedir(dp);
  return 0;
}