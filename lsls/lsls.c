#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
	char 					*current_dir;
	DIR 					*dirp;
	struct dirent *dir_entry;

  // Parse command line
	if (argc < 2)
		current_dir = ".";
	else
		current_dir = argv[1];

  // Open directory
	if (!(dirp = opendir(current_dir)))
	{
		printf("ls: %s: %s\n", current_dir, "No such file or directory");
		exit(0);
	}
  // Repeatly read and print entries
	while ((dir_entry = readdir(dirp)))
	{
		printf("%s\n", dir_entry->d_name);
	}
  // Close directory
  closedir(dirp);

  return 0;
}
