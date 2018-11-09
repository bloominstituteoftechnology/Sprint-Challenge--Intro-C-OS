#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  	// Parse command line
	int n;
        n = argc-1;
	char *c;

        if(n==0){               // if no arguments are provided, print out the contents of the current directory,  
		c="."; 
        }
	else{			//if the user provides a path
		c=argv[1];
	}
		
       		// Open directory
		DIR *dir;
    		struct dirent *ent;
    		char buffer[128];
    		strcpy(buffer, c);    		//copy the path into the buffer
    		dir = opendir(buffer);   	//Open the directory
		
		
		if (dir == NULL) {
            		printf("Cannot open directory '%s'. Please provide correct path and directory name.\n", argv[1]);
            		return 1;
        	}
		else{

		while((ent=readdir(dir))!=NULL)    //Repeatly read and print entries
            	printf("%s\n", ent->d_name);

    		}
		
    		// Close directory
		closedir(dir);	
  return 0;
}
