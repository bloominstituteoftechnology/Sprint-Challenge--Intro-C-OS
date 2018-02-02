#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <linux/limits.h>
#include <stdlib.h>
void printFiles(char *dirName) {
    DIR *dir;
    struct dirent *dent;
    struct stat statBuf;
    char relPath[512];
    char fullPath[512];
    const char * relPathFormat = (dirName[strlen(dirName) -1] == '/') ? "%s%s" : "%s/%s";
    dir = opendir(dirName);  
    if(dir!=NULL)
    {
        // char buf[512];
        while((dent=readdir(dir))!=NULL) {
            //printf(strlen(dent->d_name) > 7 ? "%s\t%10d\n" :  "%s\t\t%10d\n", dent->d_name, dent->d_reclen);
            sprintf(relPath, relPathFormat, dirName, dent->d_name);
            realpath(relPath, fullPath);
            stat(fullPath, &statBuf);
            // printf("fullPath: %s  st_mode %0xd  S_IFREG: %0xd  S_IFDIR: %0xd  S_IFMT: %0xd  st_size: %ld   dent->d_reclen: %d\n", 
            //   fullPath, statBuf.st_mode, S_IFREG, S_IFDIR, S_IFMT, statBuf.st_size, dent->d_reclen );
            if (statBuf.st_mode & S_IFREG)
              printf(" %10ld\t%s\n", statBuf.st_size, dent->d_name);            
            else if (statBuf.st_mode & S_IFDIR)
              printf("DIR        \t%s\n", dent->d_name);
            else if (statBuf.st_mode & S_IFLNK)
              printf("LINK       \t%s\n", dent->d_name);
            else 
              printf("UNK/DEVICE\t%s\n", dent->d_name);
        }
    }
    closedir(dir);  
}
/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory

  // Repeatly read and print entries
  puts("      Length\n");
  if (argc < 2) printFiles(".");
  // Close directory
  for (int i = 1; i < argc; i++)
    printFiles(argv[i]);
  return 0;
}