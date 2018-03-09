#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */

void printEntries(char* dirname) {
	DIR* handle = opendir(dirname);
	struct dirent* entry = NULL;
	do {
		entry = readdir(handle);
		if(entry == NULL)
			break;
		printf("%s\n", entry->d_name);
	} while(entry != NULL);
	closedir(handle);
}

int main(int argc, char **argv)
{
	if(argc == 1)
		printEntries(".");
	else
		printEntries(argv[1]);

  // Parse command line

  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}
