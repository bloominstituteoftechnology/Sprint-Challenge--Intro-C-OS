#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *dir_arg;
  if (argc > 1) {
    dir_arg = argv[1];
  } else {
    dir_arg = ".";
  }

  // Open directory
  DIR *dir;
  struct dirent *dp;
  char *file_name;
  struct stat buff;
  dir = opendir(dir_arg);
  if (dir == NULL) {
    printf("There was an error reading that directory\n");
    return 0;
  }
  
  // Repeatly read and print entries
  stat(dir_arg, &buff);
  while((dp=readdir(dir)) != NULL) {
      char fullpath[100];
      file_name = dp->d_name;
      sprintf(fullpath, "%s/%s", dir_arg, file_name);
      stat(fullpath, &buff);
      if ((buff.st_mode & S_IFDIR) != 0) {
        printf("          <DIR> | %s/\n", file_name);
      } else {
        printf("%10lldbytes | %s\n", buff.st_size, file_name);
      }
  }
  // Close directory
  closedir(dir);
  return 0;
}
