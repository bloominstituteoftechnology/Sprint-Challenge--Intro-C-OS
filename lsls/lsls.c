#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *entry;
  struct stat buf;
  // Open directory
  dir = opendir(".");
  // Parse command line
  if (argc > 1)
  {
    dir = opendir(argv[1]);
  }

  if (dir == NULL)
  {
    printf("Error in opening directory!\n");
  }
  else
  {
    // Repeatly read and print entries
    while ((entry = readdir(dir)) != NULL)
    {
      stat(entry->d_name, &buf);
      printf("  %10lld  %s\n", buf.st_size, entry->d_name);
    }
    // Close directory
    closedir(dir);
  }

  return 0;
}