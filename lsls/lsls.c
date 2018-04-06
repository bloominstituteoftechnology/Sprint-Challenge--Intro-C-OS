#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *entry;
  char currentDir = [1024];
  // Parse command line
  if (argc > 1)
  {
    sprintf(currentDir, "%s", argv[1]);
  }
  else
  {
    sprintf(currentDir, "%s", ".");
  }

  // Open directory
  
  // Repeatly read and print entries
  if ((dir = opendir(currentDir)) == NULL)
  {
    perror("opendir error");
  }
  else
  {
    while ((entry = readdir(dir)) != NULL)
    {
      struct stat buf;
      char type[1024];
      stat(entry->d_name, &buf);
      if (entry->d_type == DT_DIR)
      {
        sprintf(type, "%s", "<DIR>");
      }
      else
      {
        sprintf(type, "%ld", buf.st_size);
      }
      printf("  %6s  %s\n", type, entry->d_name);
    }
    closedir(dir);
  }

  // Close directory

  return 0;
}
