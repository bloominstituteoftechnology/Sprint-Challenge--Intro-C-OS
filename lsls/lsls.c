#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
   struct dirent *d;
  DIR *open;
  open = opendir(argv[1]);
  if (argc < 2) {
    open = opendir(".");
  }
  if (open == NULL){
    printf("cannot open directory: %s\n", argv[1]);
    return 1;
  }
  while ((d = readdir(open)) != NULL) {
    printf("%s\n", d->d_name);
  }
  closedir(open);
  return 0;

}