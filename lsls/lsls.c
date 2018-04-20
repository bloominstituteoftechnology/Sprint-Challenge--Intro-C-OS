#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // no arguments provided, open current directory
  if (argc == 1)
  {
    //DIR data type represents a directory stream.
    //Use opendir to open a directory stream
    DIR *d;
    //Check if no argument is provided to command line
    //Assign d pointer the result of opendir
    d = opendir(".");
    printf("Directory: Current\n");

    //Pointer to
    struct dirent *ent;
    //NULL means no more entries
    while ((ent = readdir(d)) != NULL)
    {
      printf("%s\n", (*ent).d_name);
    }
    printf("\n");
    closedir(d);
  }
  else
  {
    for (int i = 1; i < argc; i++)
    {
      DIR *d;
      d = opendir(argv[i]);
      printf("Directory: %s\n", argv[i]);

      struct dirent *ent;
      while ((ent = readdir(d)) != NULL)
      {
        printf("%s\n", (*ent).d_name);
      }
      printf("\n");
      closedir(d);
    }
  }

  return 0;
}