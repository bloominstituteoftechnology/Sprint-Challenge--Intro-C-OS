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
	char *commands[10];
	commands[0] = "ls";
 	commands[1] = "-la";
 	commands[2] = NULL;

        if(n==0){               // if no arguments are provided, print out the contents of the current directory,  
               execvp(commands[0], commands);
	       perror("exec");
	       exit(1); 
        }
	else{			//if the user provides a path

		 // Open directory
		DIR *dir;
    		struct dirent *ent;

    		char buffer[50];

    		strcpy(buffer, argv[1]);    //copy the path into the buffer
    		dir = opendir(buffer);   //Open the directory
		
		
		if (dir == NULL) {
            		printf ("Cannot open directory '%s'. Please provide correct path and directory name.\n", argv[1]);
            		return 1;
        	}
		else{

		while((ent=readdir(dir))!=NULL)    //Repeatly read and print entries
            	printf("%s\n", ent->d_name);

    		}
		
    		// Close directory
		closedir(dir);	
	}
  return 0;
}
