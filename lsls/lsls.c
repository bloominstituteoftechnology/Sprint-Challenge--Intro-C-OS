#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

#define MAX_COMMANDLINE_LEN 8192
/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *dirname = argv[0];
  if (dirname == NULL) {
    dirname = ".";
  }
  // Handle built-ins
  else if (strcmp(dirname, "exit") == 0) {
    // Exit
    exit(0);
  }

  char *exec_commands[3];
  exec_commands[0] = "ls";
  exec_commands[1] = dirname;
  exec_commands[2] = NULL;

  // Open directory
  DIR *dir;
  if ((dir = opendir(dirname)) == NULL) {
    perror ("Cannot open that directory");
    exit (1);
  }
  // Repeatly read and print entries
  struct dirent *dp;
  char *file_name;
  while ((dp=readdir(dir)) != NULL) {
    file_name = dp->d_name;
    printf("%s\n", file_name);
  }
  // Close directory
  closedir(dir);

	// Try to fork and exec the requested process
	pid_t pid = fork();

	if (pid == 0) {
		execvp(exec_commands[0], exec_commands);
		perror("exec");
		exit(1);
	} else {
		wait(NULL);
	}

  return 0;
}
