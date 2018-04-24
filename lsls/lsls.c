#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
  struct stat st;
  struct dirent *d;
  DIR *dir = opendir(argv[1]);

  if (dir == NULL)
  {
    printf("Could not open current directory");
    return 0;
  }
  else
  {
    while ((d = readdir(dir)) != NULL)
    {
      if ((strcmp(d->d_name, ".") == 0 || strcmp(d->d_name, "..") == 0 || (*d->d_name) == '.'))
      {
      }
      else
      {
        printf("%s  --  ", d->d_name);
        printf("\n");
        stat(d->d_name, &st);
       // printf("File size: %d bytes\n", st.st_size);
        printf("%u bytes\n", (unsigned int)st.st_size);

      }
    }
  }
  close(dir);
  return 0;
}