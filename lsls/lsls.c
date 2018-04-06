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
  char currentDir[1024];
  // Parse command line
  if (argc > 1)
  {
    sprintf(currentDir, "%s", argv[1]);
    // printf("%s", currentDir);
  }
  else
  {
    sprintf(currentDir, "%s", ".");
  }

  // Open directory
  // Handle Error
  if ((dir = opendir(currentDir)) == NULL)
  {
  perror("ERROR");
  }
  // If can open dir then read inside.
  else
  {
    while ((entry = readdir(dir)) != NULL)
    // new line for every directory
    // print size in bytes
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
        // print in bytes
        sprintf(type, "%ld", buf.st_size);
      }
      printf("  %6s  %s\n", type, entry->d_name);
    }
    closedir(dir);
  }

  return 0;
}