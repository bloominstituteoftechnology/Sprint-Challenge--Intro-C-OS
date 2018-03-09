#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */

void printEntries(char* dirname) {
	DIR* handle = opendir(dirname);
	struct dirent* entry = NULL;
	struct stat buf;
	do {
		entry = readdir(handle);
		if(entry == NULL)
			break;
		stat(entry->d_name, &buf);
		if((buf.st_mode & S_IFDIR) == 0)
			printf("%lld\t%s\n", buf.st_size, entry->d_name);
		else
			printf("<DIR>\t%s\n", entry->d_name);
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
