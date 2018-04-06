#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  char *p;
  struct dirent *dir;
  struct stat buf;
  // Parse command line
  if (argc > 1) 
  {
    p = argv[1];
  }
  else
  {
    p = ".";
  }

  // Open directory
  DIR *d = opendir(p);
  // Repeatly read and print entries
  if (d) {
    while((dir = readdir(d)) != NULL) {
      stat(dir->d_name, &buf);
      (buf.st_mode & S_IFDIR) ? printf("%10s   %s\n", "<DIR>", dir->d_name) : printf("%10lu  %s\n", buf.st_size, dir->d_name);
    }
  } else {
    printf("The directory %s does not exist.\n", p);
  }
  // Close directory
  closedir(d);

  return 0;
}