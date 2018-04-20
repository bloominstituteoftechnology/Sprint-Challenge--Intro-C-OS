#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

DIR *dir;
struct dirent *ent 
char currentDir[1024];

if (argc > 1)
{
  sprintf(currentDir, "%s", argv[1]);
} else {
  sprintf(currentDir, "%s", ".");
}

Dir *dir = opendir(".");
printf("Directory: Current\n");
  
  // Open directory

if ((dir = opendir(currentDir)) == NULL) {
  perror("Error opening Directory");
}

while ((dp = readdir(dir)) != NULL) {
  printf("%s\n", dp -> d_name)
}

  // Repeatly read and print entries

int closeDir(DIR *dir);

  // Close directory

  return 0;
}