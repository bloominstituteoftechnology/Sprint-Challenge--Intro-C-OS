#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>  // needed for stat()
/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
   if (argc > 1)
  {
    char *path = argv[1];
  // Open directory
   DIR *directory = opendir(path);

   // Repeatly read and print entries
    if (directory != '\0')
    {
      struct dirent *entry;
      // we want to go through each valid directory 
      while ((entry = readdir(directory)) != '\0')
      {
        char printString[1024];
      // we need to grab each d_name        
        char *filename = entry->d_name;

        struct stat buf;

        stat(filename, &buf);

        int filesize = buf.st_size;
        // will throw error if empty so make sure to check that with bitwise AND so we can get the size of directory file
        if ((buf.st_mode & S_IFDIR) != 0) {
        // print <DIR> if file is a directory
          sprintf(printString, "%10s  %s\n", "<DIR>", filename);
        } //check for regular files with another bitwise AND
        else if ((buf.st_mode & S_IFREG) != 0) {
          // print out  size in bytes of each file and the name in field of width 10
          sprintf(printString, "%10lld  %s\n", filesize, filename);
        }
        else {
         
          sprintf(printString, "--");
        }

        printf("%s", printString);

      }

      // Close directory
      closedir(directory);
    }

  }

  return 0;
}