#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  DIR *directory;
  struct dirent *entry;
  int count;

  if (argc < 2)
  {
    directory = opendir(".");

    if (directory == NULL)
    {
      printf("Error: Unable to find a folder matching the argument recieved. Exiting process.");
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
      printf("Error: Unable to find a folder matching the argument recieved. Exiting process.");
      exit(1);
    }
  }
  while ((entry = readdir(directory)) != '\0')
  {
    printf("%s ", entry->d_name);
  }
  printf("\n");
  closedir(directory);

  return 0;
}