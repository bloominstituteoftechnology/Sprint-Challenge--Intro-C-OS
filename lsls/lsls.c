#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  // Open directory

  DIR *dir;

  struct dirent *entry;
  char currentDir[1024];

  // Repeatly read and print entries
  if (argc > 1) 
  {
    sprintf(currentDir, "%s", argv[1]);
  } else {
    
      sprintf(currentDir, "%s", ".");
    }

  if ((dir = opendir(currentDir)) == NULL)
  
  {
    perror("There was an error opening this directory");
  } else {
  // Close directory
  while ((entry = readdir(dir)) != NULL)
  {
    struct stat buf;
    char type[1024];
    stat(entry -> d_name, &buf);
    if (entry -> d_type == DT_DIR)
    {
      sprintf(type, "%s", "<DIR>");
    }
    else
    {
      sprintf(type, "%ld", buf.st_size);
    }
     printf(" %8s\n", entry-> d_name);
   }
  closedir(dir);
  }

  return 0;
}