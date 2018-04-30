#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */
void print_all(DIR *dir, char given_path[])
{
  struct dirent *entry;
  struct stat size;
  char actual_path[100];

  // printf("here is the full dir currently: %s\n", dir);

  while ((entry = readdir(dir)) != NULL)
  {
    sprintf(actual_path, "%s/%s", given_path, entry->d_name);
    stat(actual_path, &size);
    if ((size.st_mode & S_IFDIR) != 0)
    {
      printf("%10s %s\n", "<DIR>", entry->d_name);      
    }
    else if ((size.st_mode & S_IFREG) != 0)
    {
      printf("%10ld %s\n", size.st_size, entry->d_name);
    }
    else
    {
      printf("%10s %s\n", "", entry->d_name);      
    }
  }
}

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
    closedir(opened_dir);    
    exit(1);
  }

  // Repeatly read and print entries
  print_all(opened_dir, path);

  // Close directory
  closedir(opened_dir);

  return 0;
}