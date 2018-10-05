#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>

#define S_IFMT 0160000
#define S_IFDIR 0040000
#define S_IFREG 0100000 

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
    fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
    exit(EXIT_FAILURE);
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
    if((buf.st_mode & S_IFMT) == S_IFDIR)
    {
      printf("%10s  %s\n", "<DIR>", entry->d_name);
    }
    else if((buf.st_mode & S_IFMT) == S_IFREG)
    {
      printf("%10lld  %s\n", buf.st_size, entry->d_name);
    }
  }

  // Close directory
  if(closedir(dir) == -1)
  {
    perror("closedir");
    exit(1);
  }

  return 0;
}
