#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
	DIR *d;
	char cDir[1024];

	// Reads Args	
	sprintf(cDir, "%s", argv[1]);
	
	// Open directory
	struct dirent *e;
	while ((e = readdir(d)) != NULL)
	{
		WriteDir(e);
	}

	// close when done
	closedir(d);

	return 0;
}

/**
* Writes the current Dir
*/
void WriteDir(struct dirent *e)
{
	struct stat buf;
	char type[1024];

	printf("  %12s  %s\n", type, e->d_name);
}