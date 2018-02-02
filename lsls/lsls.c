#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  //****** Parse command line
  int count;

  printf("There are %d command line argument(s):\n", argc);

  for (count = 0; count < argc; count++)
  {
    printf("  argv[%d]= `%s`\n", count, argv[count]);
  }

  //****** Open directory
  struct dirent *pDirent;
  DIR *directory;

  directory = opendir(".");
  if (directory == NULL)
  {
    printf("Cannot open directory '%s'\n", argv[1]);
    return 0;
  }

  //****** Repeatly read and print entries
  struct stat buf;
  printf("directory size is %lld\n", buf.st_size);
  // int result;
  // char directoryName[50];
  // char dot[50];

  // strcpy(dot, ".");
  // strcpy(directoryName, "pDirent->d_name");

  // result = strcmp(dot, directoryName);

  while ((pDirent = readdir(directory)) != NULL)
  {

    stat(pDirent->d_name, &buf);

    if ((buf.st_mode & S_IFDIR) > 0)
    { //Test DIR or file
      printf("<DIR> %s\n", pDirent->d_name);
    }
    if ((buf.st_mode & S_IFREG) > 0)
    printf("%10lld [%s]\n", buf.st_size, pDirent->d_name);
  }

  //****** Close directory
  closedir(directory);

  return 0;
}