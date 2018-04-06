#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  for (int i = 0; i < argc; i++)
  {
    char *path = argv[i];

    /* case when user provides no dirs */
    if (i == 0 && argc == 1)
    {
      path = ".";
    }

    if (i == 0 && argc > 1)
    {
      /* if user provides dirs */
      /* skip zero-index argv  */
    }

    else
    {
      // Open directory
      DIR *directory = opendir(path);

      /* check if directory is NULL */
      if (directory == NULL)
      {
        printf("<< PATH: %s >> not found.\nError: %s\n", path, strerror(errno));
        exit(1);
      }

      // Repeatly read and print entries
      else
      {
        struct dirent *ent;

        printf("<< PATH: %s >>\n", path);

        while ((ent = readdir(directory)) != NULL)
        {
          char *file = ent->d_name;
          char *path_file = malloc(strlen(path) + strlen("/") + strlen(file) + 1);

          struct stat buf;

          int isDir = buf.st_mode & S_IFDIR;
          int isFile = buf.st_mode & S_IFREG;

          sprintf(path_file, "%s/%s", path, file);
          stat(path_file, &buf);

          if (isDir)
          {
            printf("%10s  %s\n", "<DIR>", file);
          }

          else if (isFile)
          {
            printf("%10lld  %s\n", buf.st_size, file);
          }

          else
          {
            printf("%10lld  %s\n", buf.st_size, file);
          }
        }
      }

      // Close directory
      closedir(directory);
      printf("\n\n");
    }
  }

  return 0;
}