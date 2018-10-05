#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
	DIR *dir;
	struct dirent *dp;
	struct stat buf;

	// Parse command line
	// Open directory
	if (argc < 2) {
		dir = opendir(".");
	}
	else {
		dir = opendir(argv[1]);
	}
	stat(dir, &buf);
	// Repeatly read and print entries
	while ((dp = readdir(dir)) != NULL) {
		printf("%10ld %s\n", buf.st_size, dp->d_name);
	}

	// Close directory
	closedir(dir);
	return 0;
}