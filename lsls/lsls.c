#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  // Open directory
	DIR *directory = opendir(".");

	if(directory == NULL){
		printf("Unable to open .");
		exit(1);
	}

   // Repeatly read a
	struct dirent *ent = readdir(directory);
	ent = readdir (directory);

   while (ent != NULL) {
		printf("%s\n", ent->d_name);
		ent = readdir(directory);
	}

   // Close directory
	closedir (directory);

  return 0;
}