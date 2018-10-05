#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory
  DIR *dir;

  // Check command line args
  if(argc == 2)
  {
    dir = opendir(argv[1]);
  }
  else if(argc > 2)
  {
    printf("Expected 0 or 1 args!\n");
    dir = opendir(".");
  }
  else
  {
    dir = opendir(".");
  }

  if(dir == NULL)
  {
    perror("opendir");
    exit(1);
  }

  // Repeatly read and print entries
  struct dirent *entry;

  while((entry = readdir(dir)) != NULL)
  {
    if(entry->d_name[0] == ".") continue;
    printf(" %s\n", entry->d_name);
  }

  // Close directory
  if(closedir(dir) == -1)
  {
    perror("closedir");
    exit(1);
  }

  closedir(dir);

  return 0;
}
