#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
// With argc (argument count) and argv (argument vector) you can get the number and the values of passed arguments when your application has been launched.
int main(int argc, char **argv)
{
  // Parse command line
  if (argc > 2)
  {
    puts("Use command line like this: ./lsls <directory name>");
    return 0;
  }
  // Open directory
  DIR *d;
  if (argc == 1)
  {
    d = opendir(".");
  }
  else
  {
    d = opendir(argv[1]);
  }
  // Repeatly read and print entries
  struct dirent *ent;

  // foo->bar is equivalent to (*foo).bar, i.e. it gets the member called bar from the struct that foo points to.
  if (d)
  {
    while ((ent = readdir(d)) != NULL)
    {
      printf("%s\n", ent->d_name);
    }
    // Close directory
    closedir(d);
  }
  else
  {
    printf("Directory %s doesn't exist \n", argv[1]);
  }

  return 0;
}