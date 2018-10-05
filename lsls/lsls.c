#include <stdio.h>
#include <dirent.h>
#include <stdlib.h> 
#include <sys/stat.h>


int main(int argc, char **argv)
{
  struct dirent *ent;
  struct stat buf;

  int count;
  printf("There are %d command line argument(s):\n", argc);
  for(count=0; count<argc; count++){
    puts(argv[count]);
  }

  if (count < 2){
    DIR *dr = opendir(".");
    while((ent = readdir(dr)) != NULL){
      printf("%s\n", ent->d_name);
    }

    closedir(dr);
  }

  else{
    DIR *dr = opendir(argv[1]);

    if(dr == NULL){
      fprintf(stderr, "Error: Could not open directory");
      exit(1);
    }

  while((ent = readdir(dr)) != NULL){
    stat(argv[1], &buf);
    printf("%10lld", buf.st_size);
    printf("%s\n", ent->d_name);
  }

  closedir(dr);
}
  
  return 0;
}