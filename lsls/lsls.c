#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
/**
 * Main
 */
int main(int argc, char **argv)
{
  
  DIR *directory;
  struct dirent *entry;
  char currentDirectory[1024];
  
  // Parse command line
 if (argc > 1) {
    sprintf(currentDirectory, "%s", argv[1]);
  } else {
    sprintf(currentDirectory, "%s", ".");
  }

  // Open directory
  if ((directory = opendir(currentDirectory)) == NULL) {
    
    perror("The Directory can not be opened.");

  }

  // Repeatly read and print entries
  else {
    while ((entry = readdir(directory)) != NULL) {

      /* The st_size field gives the size of the file
      (if it is a regular file or a symbolic link) in bytes.
      The size of a symbolic link is the length of the pathname it contains,
      without a terminating null byte. */

      struct stat st;
      char type[1024];
      stat(entry->d_name, &st);
      long size = st.st_size;
      
      /* Checking if the type is <DIR> from the available macro constants
      for the value returned in d_type
      SOURCE: http://man7.org/linux/man-pages/man3/readdir.3.html */

      if (entry->d_type == DT_DIR) {
        sprintf(type, "%s", "<DIR>");
      } else {
        sprintf(type, "%ld", size);
      }

      printf("%6s %s\n", type, entry->d_name);

    }
  // Close directory
    closedir(directory);
  }

  return 0;
}