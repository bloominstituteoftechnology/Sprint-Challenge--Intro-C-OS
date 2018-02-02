#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
char *getcwd(char *buf, size_t size);

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *pDirent;
  DIR *pDir;
  char cwd[1024];
  struct stat statBuf;

  if (argc < 2)
  {
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
      pDir = opendir(cwd);
      while ((pDirent = readdir(pDir)) != NULL)
      {
        printf("[%s]\n", pDirent->d_name);
        if (!stat(pDirent->d_name, &statBuf))
        {
          printf("\t\t%ld bytes\n", statBuf.st_size);
        }
        else
        {
          printf("(size unavailable for this file)\n");
        }
      }
      closedir(pDir);
      return 0;
    }
  }
  else if (argc >= 2)
  {
    pDir = opendir(argv[1]);
  }
  if (pDir == NULL)
  {
    printf("Cannot open directory '%s'\n", argv[1]);
    return 1;
  }

  do
  {
    pDirent = readdir(pDir);
    if (pDirent)
    {
      printf("%s -- ", pDirent->d_name);
      if (!stat(pDirent->d_name, &statBuf))
      {
        printf("\t\t%ld bytes\n", statBuf.st_size);
      }
      else
      {
        printf("(size unavailable for this file)\n");
      }
    }

  } while (pDirent);
  closedir(pDir);
  return 0;
}
