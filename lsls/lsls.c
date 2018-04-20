#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
	DIR *opened;

	// if only one argument is passed in, open current directory
	if (argc == 1) {
		opened = opendir(".");
	} 
	// if more than one argument is passed in open the specified directory
	else {
		argv++;
		opened = opendir(*argv);
	}

	// if opendir encountered an error, print message and exit program
	if (opened == NULL) {
		printf("There was an error opening the directory.");
		exit(1);
	}

	// read the opened directory
	struct dirent *directory = readdir(opened);

	// iterate through the files in the directory and print each
	do {
		printf("%s\n", directory->d_name);
		directory = readdir(opened);
	}
	while (directory != NULL);

  // Close directory
	closedir(opened);

  return 0;
}
