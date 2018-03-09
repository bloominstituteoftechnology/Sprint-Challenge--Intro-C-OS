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
  struct dirent *sd;
  char location[80];

  if (argv == NULL)
  {
    dir = opendir(".");
  } else
  {
    for (int i = 0; argv[i] != '\0'; i++)
    {
      printf("Dir: %s\n", argv[i]);
      sprintf(location, "%s%s", location, argv[i]);
    }
    dir = opendir(location);
  }
  // handle error if null
  if (dir == NULL)
  {
    printf("Error! Cannot open directory\n");
    exit(1);
  }
  
  // Repeatly read and print entries
  while ( (sd = readdir(dir)) != NULL )
  {
    printf("%s\n", sd->d_name);
  }


  // Close directory
  closedir(dir);
  return 0;
}