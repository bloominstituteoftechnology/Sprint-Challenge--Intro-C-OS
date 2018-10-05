#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  struct dirent *ent;
  int count;
  for(count=0; count<argc; count++){
    puts(argv[count]);
  }

  // Open directory
  DIR *dr = opendir(".");
  if (dr == NULL) {
    printf("Error: Could not open directory");
    return 0;
  }
  // Repeatly read and print entries
  while((ent = readdir(dr)) != NULL){
    printf("%s\n", ent->d_name);
  }
  // Close directory
  closedir(dr);
  return 0;
}