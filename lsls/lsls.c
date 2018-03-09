#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line (argc = command line arg(s)?)

  // Open directory

  DIR *dir;
  struct dirent *item;
  if (argv[1]) {
    dir = opendir("%s", argv[1]);
  }
  else {
    dir = opendir(".");
  }

  if (dir == NULL)
  {
    printf("oops!");
    exit(1);
  }
  
  ///////this is a test:
  if (argv[1])
    printf("%s\n", argv[1]);

  // Repeatly read and print entries

  while(!((item=readdir(dir))=='\0'))
  {
    printf("%s\n", item->d_name);
  }

  // Close directory

  closedir(dir);

  return 0;
}