#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *entry;
  char currentDir[1024];
  // Parse command line
  sprintf(currentDir, "%s", argv[1]);
  printf("%s", currentDir);
  // Open directory
  // If cant open dir send error.
  if ((dir = opendir(currentDir)) == NULL)
  {
    perror("opendir error");
  }
  // If can open dir then read inside.
  else
  {
    while ((entry = readdir(dir)) != NULL)
    // For every result of readdir
    // within the currentDirectory
    // print a new line with it.
    {
      printf("  %s\n", entry->d_name);
    }
    closedir(dir);
  }

  return 0;
}