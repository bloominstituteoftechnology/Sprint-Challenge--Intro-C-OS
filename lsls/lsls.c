#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h> 
#include <sys/wait.h>
#include <string.h>


// https://repl.it/@codejoncode/Sprint-Project-C-list-directory

int main(int argc, char **arv) {
  
  DIR *dir; 
  struct dirent *sd; 
  char commandline;
  int i; 

  while (strcmp(&commandline, "exit")!= 0)
  {

      
      

      // commandline = '.';
      printf("Choose a directory  . for current directory .. to go back or enter directoryName  use exit to exit \n");
      scanf("%s", &commandline);
      

      if(commandline == 0)
      {
        printf("its null\n");
      }



      if (strcmp(&commandline, "exit") == 0)
      {
        printf("exiting"); 
        exit(0); 
      }

      dir = opendir(&commandline);//will go forward or back. currently. 
      if(dir == NULL)
      {
        printf("Unable to open directory.\n");
        exit(1); 
      }

      readdir(dir);

      // Repeatly read and print entries
      while ( (sd=readdir(dir)) != NULL)
      {
        printf(">> %s\n", sd->d_name);
      }
      // Close directory
      closedir(dir); 
  }


  return 0;
}