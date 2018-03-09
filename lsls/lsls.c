#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main()
{
  DIR *d; //creating a directory type called d
  struct dirent *dir; //initializing a struct
  d = opendir("."); //opening curret directory

  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    //while the dir doesn't equal null keep reading
    {
      printf("%s\n", dir->d_name); //print out files from d into dir
    }
    closedir(d); //close directory
  }

  return 0;
}