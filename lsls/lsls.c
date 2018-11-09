#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *entry;
  char currentDir[1024];
  // Parse command line
  if (argc > 1)
  {
    sprintf(currentDir, "%s", argv[1]);
    // printf("%s", currentDir);
  }
  else
  {
    sprintf(currentDir, "%s", ".");
  }

  // Open directory
  // If cant open dir send error.
  if (strcmp(currentDir, "help") == 0)
  {
    printf("\n---------------   LSLS HELP   --------------- \n\n"
          "To use this comandline program, type the following: \n\n  "      
          " ./lsls directory\n\n"
          "contents of two folders higher than your current one:\n"
          " ./lsls ../../ \n\n "
          "If no directory is specified,  lsls will assume its current location as the target directory\n"
          " \n---------------   END  HELP   ---------------\n\n");


  }
  else if ((dir = opendir(currentDir)) == NULL)
  {
    perror("opendir error");
  }
  // If can open dir then read inside.
  else if (strcmp(currentDir, "help") != 0)
  {
    while ((entry = readdir(dir)) != NULL)
    // For every result of readdir
    // within the currentDirectory
    // print a new line with it.
    {
      struct stat buf;             // Contains each item's system stats.
      char type[1024];             // Will contain File size or <DIR>.
      stat(entry->d_name, &buf);   // Extracts stats into buf.
      if (entry->d_type == DT_DIR) // Checks to see if it is a directory.
      {
        sprintf(type, "%s", "<DIR>"); // assigns <DIR> to the type char array.
      }
      else // In the case it is not a directory
      {
        sprintf(type, "%ld", buf.st_size); // assigns the size to the type char array.
      }
      printf("  %12s  %s\n", type, entry->d_name); // Prints out a line containing type/size and name of the item.
    }
    closedir(dir);
  }

  return 0;
}