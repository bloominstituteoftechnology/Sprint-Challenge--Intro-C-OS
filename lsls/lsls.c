#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
/**
 * Main
 */
int main(int argc, char **argv)
{
  	// Parse command line
	int n;
        n = argc-1;
	char *command="ls";

        if(n==0){               // if no arguments are provided, print out the contents of the current directory,  
               execlp(command, command, NULL);
	       perror("exec");
	       exit(1); 
        }

  	// Open directory

  	// Repeatly read and print entries

  	// Close directory

  return 0;
}
