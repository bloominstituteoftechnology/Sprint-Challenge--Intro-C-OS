#include <stdio.h>
#include <dirent.h>
#include <stdlib.h> // For exit()
#include <sys/stat.h> // For struct stat
#include <string.h> // For strcat()

# define MAX_INPUT 256

/**
 * Main
 */
int main(int argc, char **argv)
{
  char path[MAX_INPUT];

  // Parse command line
  if(argc > 1){
    strcpy(path, argv[1]);
  }
  else{
    strcpy(path, ".");
  }

  printf("path: %s", path);
  // Open directory
  DIR *directory = opendir(path);
  // Repeatly read and print entries
  if(directory){
    struct stat buffer;
    struct dirent *entry = readdir(directory);
    while(entry){
      char *size_path = strcat(strcat(path, "/"), entry->d_name);
      stat(size_path, &buffer);
      S_ISDIR(buffer.st_mode) ? printf("<DIR> ") : printf("%li ", (intmax_t) buffer.st_size);
      printf("%s\n", entry->d_name);
      entry = readdir(directory);
    }
  }
  else{
    printf("Error opening directory\n");
    exit(1);
  }


  // Close directory
  closedir(directory);

  return 0;
}