// #include <stdio.h>
// #include <dirent.h>

// /**
//  * Main
//  */
// int main(int argc, char **argv)
// {
//   // Parse command line

//   // Open directory

//   // Repeatly read and print entries

//   // Close directory

//   return 0;
// }


#include <stdio.h>
#include <dirent.h>


int printFileList(char *path) {
  DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d) {
      while ((dir = readdir(d)) != NULL) {
         if (dir->d_type == DT_REG) // DT_REG == A regular file
    {
      printf("%s\n", dir->d_name); 
    }
      }
      closedir(d);
    }
    return(0);
}

int main(int argc, char *argv[]) 
{
    char *path;

   if (argc == 1)
    {
    path = ".";
    printFileList(path);
    }
    else
    {
      path=argv[1];
      printFileList(path);
    }
}