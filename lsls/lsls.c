#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

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
  struct stat buf;

  while((entry = readdir(dir)) != NULL)
  {
    stat(entry->d_name, &buf);
    printf("%10lld  %s\n", buf.st_size, entry->d_name);
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
