#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 9824
#define MAX_CMD_ARGS 128

/**
 * Main
 */
  // steps
  // Parse command line
  
  // Open directory
  
  // Repeatly read and print entries

  // Close directory



void parse_commandline(char *commandline, char *exec_commands[], int max_count)
{
  char *separators = "\r\n\t";
  char *token;
  char *str = commandline;
  int i = 0;

   while ((token = strtok(str, separators)) != NULL && i < max_count){
     str = NULL;
     exec_commands[i++] = token;
   }

  exec_commands[i] = NULL;
}


// int main(int argc, char **argv)
int main(void)
{
  char commandLine[MAX_CMD_LEN];
  char *exec_commands[MAX_CMD_ARGS];

// while (commandLine == NULL ){
//   if (commandLine == NULL) {
//       char defaultCMD = "pwd";
//       printf("testing Null");
//     exec_commands[0] = defaultCMD;
//     printf(exec_commands[0]);
//     DIR *opendir(const char *defaultCMD);

//   }

// }

  while (printf("> "), fgets(commandLine, sizeof commandLine, stdin) != NULL) {
    parse_commandline(commandLine, exec_commands,MAX_CMD_ARGS-1);

    // if (strcmp(exec_commands[0], "exit") == 0) {
    //   exit(0);
    // }else {

    // }
      DIR * dir;
      struct dirent *dp;


      if((dir = opendir(".")) == NULL) {
        perror("Cannot open");
        exit(1);
      }
      while ((dp = readdir(dir)) != NULL) {

      }
      
      
    //   int pid = fork();
    //   if (pid < 0 ) {
    //     fprintf(stderr, "Fork Failed \n");
    //     exit(1);
    //   } else if (pid == 0) {
    //     execvp(exec_commands[0], exec_commands);
    //     perror("exec");
    //     exit(1);
    //   } else {
    //     wait(NULL);
    //     // printf("Parent Process");

    //   }
    




    }

  
  return 0;
}


  






















// int main(int argc, char **argv)
// {
//   // char path = ;
//     int d = opendir("/mnt/c/Users/VLeon/Documents/Code");
//     printf("d: %s", d);
//     while(d != "\0" || NULL ){
//       printf("while loop d: %s", d);
//       readdir(d);

//     };

//   // if ((dir = opendir(".")) == NULL) {
//   //   perror("Cannot open .");
//   //   exit(1);
//   // }

//   // while ((dp = readdir(dir)) != NULL) {

//   // }
  

//   return 0;
// }




// int main(int argc, char **argv)
// {
//   char commandLine[9892];

  
//   if (pipe(p) < 0) {
//     fprintf(stderr, "fork failed\n");
//     exit(1);


//   int pid = fork();
//   }else if (pid == 0) {
//     // open

//     // read and print



//     // printf("Child Process");
//   }else {
//     wait(NULL);
//     // printf("Parent Process");

//   }

//   return 0;
// }



