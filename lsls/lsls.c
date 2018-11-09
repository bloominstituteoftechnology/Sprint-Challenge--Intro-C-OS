#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */

int main(int argc, char **argv)
{

  // Parse command line
  DIR *sp;
  struct dirent *direc;
  // Open directory
  if (argc > 2)
  {
    printf("Not Valid, Provide Single Directory\n");
    exit(1);
  }
  else if (argc < 2) 
  {
    sp = opendir(".");
  }
  else 
  {
    sp = opendir(argv[1]);
  }

  if (sp == NULL) 
  {
    printf("Not Able to Open, Provide Appropriate Value", argv[1]);
    return 1;
  }

  // Repeatly read and print entries
  while ((direc = readdir(sp)) != NULL)
    {
     printf("%s\n", direc -> d_name);
    }

  // Close directory
   closedir(sp);
   return 0;
}