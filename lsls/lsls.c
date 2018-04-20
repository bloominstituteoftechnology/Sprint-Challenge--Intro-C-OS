#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{

  char *path = argv[1];

  if(path != NULL)
  {
    printf("here is the path we want to look at %s\n", path);
  }
  else
  {
    printf("looks like we just want original dir of %s\n", argv[0]);
    path = ".";
  }
  // Parse command line
  // for(int i = 0; i < argc; i++)
  // {
  //   printf("argc is equal to %d ;\nhere is argv %c\n %s\n", argc, **argv, argv[1]);
  // }

  // Open directory
  DIR *opened_dir = opendir(path);

  if (opened_dir != NULL)
  {
    printf("opened_dir is not NULL!, and here is the path! %s\n", path);
  }
  else
  {
    printf("opened_dir is super NULL\n");
  }

  // Repeatly read and print entries

  // Close directory
  closedir(opened_dir);

  return 0;
}