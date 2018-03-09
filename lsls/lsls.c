#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
void printContent(char *path) 
{
  struct dirent *ent;
  DIR *d = opendir(path);

  if(!d)
  {
    printf("No directory found at %s", path);
  } 
  else 
  {
    while ((ent = readdir(d)) != NULL)
    {
      printf("%s\n", ent->d_name); 
    }
    closedir(d);
  }
}
int main(int argc, char **argv)
{
  char *path;

  if (argc != 1)
  {
    path = argv[1];
    printContent(path);
  }
  else
  {
    path = ".";
    printContent(path);
  }

  return 0;
}