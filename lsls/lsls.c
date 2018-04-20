#include <stdio.h>
#include <dirent.h>
#include <errno.h>

static void lookup(const char *arg)
{
	DIR *dirp;
	// struct dirent *dp;

	if ((dirp = opendir(arg)) == NULL) {
		perror("ERROR"); 
	} 
}
/**
 * Main
 */
int main(int argc, char **argv)
{
	if (argc == 1) {
		DIR *d;
		struct dirent *dir;
		d = opendir(".");
		while((dir = readdir(d)) != NULL)
		{
			printf("%s\n", dir->d_name);
		}
		closedir(d);
	}
	if (argc == 2){
		lookup(argv[1]);
		if (errno != 0) {
			return 0;
		}
		DIR *d;
		struct dirent *dir;
		d = opendir(argv[1]);
		while ((dir = readdir(d)) != NULL)
		{
/*			if (!dir->d_name) {
				printf("No such directory as  %s\n", argv[1]);
				} 
*/
			printf("%s\n", dir->d_name);
		}
		closedir(d);
	}
  return 0;
}
