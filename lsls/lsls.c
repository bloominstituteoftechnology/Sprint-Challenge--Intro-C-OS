#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
	char 					*current_dir;
	DIR 					*dirp;
	struct dirent *dir_entry;
	struct stat		buf;
	char 					path[1024];

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
		snprintf(path, sizeof(path), "%s/%s", current_dir, dir_entry->d_name);
		stat(path, &buf);
		printf("%5lld %s\n", buf.st_size, dir_entry->d_name);
	}
  // Close directory
  closedir(dirp);

  return 0;
}
