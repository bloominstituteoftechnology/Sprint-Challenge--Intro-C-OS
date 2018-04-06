#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */

int main(int argc, char **argv)
{
	struct dirent *parentDirent;
	DIR *parentDir;

	if (argc < 2) {
		parentDir = opendir(".");
		while ((parentDirent = readdir(parentDir)) != NULL) {
			printf("[%s]\n", parentDirent->d_name);
		}
		closedir(parentDir);
	}

	parentDir = opendir(argv[1]);

	if (parentDir == NULL) {
		return 1;
	}

	while ((parentDirent = readdir(parentDir)) != NULL) {
		printf("[%s]\n", parentDirent->d_name);
	}

	closedir(parentDir);
	
	return 0;
}