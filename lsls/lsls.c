#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *de;

 	if(argv[1] == NULL) {
  	DIR *dr = opendir(".");
    while ((de = readdir(dr)) != NULL){
      printf("%s\n", de->d_name);
    }
    closedir(dr);
    return 0;
		}
	else {
			char *x = argv[1];
			DIR *dr = opendir(x);
    while ((de = readdir(dr)) != NULL){
			printf("%s\n", de->d_name);
    }
    closedir(dr);
    return 0;
	}
}