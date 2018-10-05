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
  printf("There are %d command line argument(s):\n", argc);
  for(count=0; count<argc; count++){
    puts(argv[count]);
  }

  // Open directory
  if (count < 2){
    DIR *dr = opendir(".");
    while((ent = readdir(dr)) != NULL){
      printf("%s\n", ent->d_name);
    }
  // Close directory
    closedir(dr);
  }

  else{
    DIR *dr = opendir(argv[1]);
  // Repeatly read and print entries
  while((ent = readdir(dr)) != NULL){
    printf("%s\n", ent->d_name);
  }
  // Close directory
  closedir(dr);
}
  

  return 0;
}