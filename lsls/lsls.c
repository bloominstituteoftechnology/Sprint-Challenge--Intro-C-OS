#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  DIR *directory;
  struct dirent *entry;
  int count;

  if (argc == 1)
  {
    directory = opendir(".");

    if (directory == NULL)
    {
      printf("Error: Unable to read the contents of the directory without any arguements. Exiting process.");
      exit(1);
    }
  }
  else if (argc == 2)
  {
    int check = strcmp(argv[1], "help");
    if (check == 0)
    {
      printf("Usage: ls already does a good job but one would add this to path.\n\"lsls\" will list the directory contents of the folder you are currently in.\n");
      printf("\"lsls ..\" will list the directory contents of the parent folder.\n");
      printf("\"lsls ../../<folder>\" will list the directory contents of the specific <folder>.\n");
      exit(0);
    }
    directory = opendir(argv[1]);
    
    if (directory == NULL)
    {
      printf("Error: Unable to read the contents of the directory within the arguments provided. Exiting process.");
      exit(1);
    }
  }
  // Open directory

  // Repeatly read and print entries
  while ((entry = readdir(directory)) != '\0')
  {
    printf("%s ", entry->d_name);
  }
  printf("\n");
  // Close directory
  closedir(directory);

  return 0;
}