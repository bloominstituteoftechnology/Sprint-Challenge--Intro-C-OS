#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  for (int i = 1; i < argc; i++)
  {
    printf("argv %s \n", argv[i]);
  }
  DIR *dir;
  struct dirent *entry;

  if ((dir = opendir("/Users")) == NULL)
    perror("opendir() error");
  else
  {
    puts("contents of root:");
    while ((entry = readdir(dir)) != NULL)
      printf("  %s\n", entry->d_name);
    closedir(dir);
  }
  // struct dirent *entry;

  // DIR *d = opendir(".");
  // entry = readdir(d);
  // printf(" %s\n", entry->d_name);
  // printf("Testing: %s\n", d == NULL ? "FAIL" : "PASS");
  // closedir(d);
  // Open directory

  // Repeatedly read and print entries

  // Close directory

  return 0;
}