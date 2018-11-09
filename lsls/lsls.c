#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  DIR *dir;
  struct dirent *ent;
  // Open directory
  dir = opendir("."); // open current directory
  if (argc > 1)
  {
    dir = opendir(argv[1]); //open input dir
  }
  if (dir == NULL) // null edge case
  {
    printf("No Directory found \n");
  }
  else
  {
    // Repeatly read and print entries
    while ((ent = readdir(dir)) != NULL) // while entry in direction is not null
    {
      printf("  %s\n", ent->d_name); // print directory name
    }
    // Close directory
    closedir(dir);
  }
  return 0;
}