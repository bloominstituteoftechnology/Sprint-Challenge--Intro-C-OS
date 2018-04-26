#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>


/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
	struct dirent *direntry;
	char currentdir[1024];
	// Parse command line
	if (argc > 1)
	{
	  sprintf(currentdir, "%s", argv[1]);
	}
	else 
	{
	  sprintf(currentdir, "%s", ".");
	}

  // Open directory
	if (strcmp(currentdir, "help") == 0)
  {
	  printf("\n# # LSLS HELP   # # \n To use this comandline program\n type the following: \n\n        ./lsls directory\n\n The following example will display the contents\n of two folders outside of your current one:\n\n        ./lsls ../../\n\n Thank you for using lsls\n# # # # # # # #   END  HELP   # # # # # # # #\n\n");
  }
	else if ((dir = opendir(currentdir)) == NULL)
	{
	 perror("opendir error");
	}
  else if (strcmp(currentdir,"help") !=0)
	{
	  while ((direntry = readdir(dir)) !=NULL)
		{
		  struct stat buf;  // system stat for each item
			char type[1024]; // File size or dir
			stat (direntry->d_name, &buf); // stats are stored into a buff.
			if (direntry->d_type == DT_DIR) // check if its a directory
			{
			 sprintf(type, "%s", "<DIR>"); // assigns DIR to the char type array.
			}
      else 
			{
			  sprintf(type, "%ld", buf.st_size); // assigns size to the char type array.
			}
			printf(" %12s %s\n", type, direntry->d_name); // prints a line with the size and name of the item.
			}
			closedir(dir);
		}
	// Repeatly read and print entries

  // Close directory

  return 0;
}
