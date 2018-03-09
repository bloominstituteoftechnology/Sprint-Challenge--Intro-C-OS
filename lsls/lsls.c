#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Open directory
  DIR *dir;
  struct dirent *item;
  // Parse command line (argc = command line arg(s)?)
  if (argv[1]) {
    dir = opendir(argv[1]);
  }
  else {
    dir = opendir(".");
  }
  if (dir == NULL)
  {
    printf("oops!");
    exit(1);
  }
  if (argv[1])
    printf("Showing contents of: %s\n", argv[1]);

  // Repeatly read and print entries
  while(!((item=readdir(dir))=='\0'))
  {
    printf("%s\n", item->d_name);
  }

  // Close directory
  closedir(dir);
  return 0;
}