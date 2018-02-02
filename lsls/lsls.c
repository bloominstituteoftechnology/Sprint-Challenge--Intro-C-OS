#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

struct dirent *pDirent;
struct stat buf;

/**
 * It's a helper function from the stack overflow otherwise I would use strcopy
 * Extracts a selection of string and return a new string or NULL.
 * It supports both negative and positive indexes.
 */
char *
str_slice(char str[], int slice_from, int slice_to)
{
    // if a string is empty, returns nothing
    if (str[0] == '\0')
        return NULL;

    char *buffer;
    size_t str_len, buffer_len;

    // for negative indexes "slice_from" must be less "slice_to"
    if (slice_to < 0 && slice_from < slice_to) {
        str_len = strlen(str);

        // if "slice_to" goes beyond permissible limits
        if (abs(slice_to) > str_len - 1)
            return NULL;

        // if "slice_from" goes beyond permissible limits
        if (abs(slice_from) > str_len)
            slice_from = (-1) * str_len;

        buffer_len = slice_to - slice_from;
        str += (str_len + slice_from);

    // for positive indexes "slice_from" must be more "slice_to"
    } else if (slice_from >= 0 && slice_to > slice_from) {
        str_len = strlen(str);

        // if "slice_from" goes beyond permissible limits
        if (slice_from > str_len - 1)
            return NULL;

        buffer_len = slice_to - slice_from;
        str += slice_from;

    // otherwise, returns NULL
    } else
        return NULL;

    buffer = calloc(buffer_len, sizeof(char));
    strncpy(buffer, str, buffer_len);
    return buffer;
}

/**
 * Function that prints out a directory listing for the
 * path the user specifies on the command line.
 */

int printDirectory(char *path)
{
  // Open directory
  DIR *pDir = opendir(path);
  if (pDir == NULL) {
    printf ("Cannot open directory '%s'\n", path);
    return 1;
  }
  // Repeatly read and print entries
  while ((pDirent = readdir(pDir)) != NULL) {
    stat(pDirent->d_name, &buf);
    if((buf.st_mode & S_IFDIR) != 0) {
      printf ("     <DIR> %s\n", pDirent->d_name);
    } else if ((buf.st_mode& S_IFREG) != 0) {
      printf ("%10ld %s\n", buf.st_size, pDirent->d_name);
    } else {
      printf ("%s\n", pDirent->d_name);
    }
  }
  // Close directory
  return 0;
}

/**
 * Main
 */
int main(int argc, char **argv)
{
  if (argc == 1) {
    // Listing current directory
    // Get rid of lsls.exe at the end of the path
    char *lastOccurrence = strrchr( argv[0], '\\' );
    int endIndex = strlen(argv[0]) - strlen(lastOccurrence) + 1; // there is probably a better way of doing this
    char *path = str_slice(argv[0], 0, endIndex);
    printDirectory(path);
  } else if (argc == 2) {
    // Listing specified directory
    // By the same principle
    char *lastOccurrence  = strrchr( argv[0], '\\' );
    int endingIndex = strlen(argv[0]) - strlen(lastOccurrence) + 1;
    char *ending = strcat(argv[1], "\\");
    char *path = strcat(str_slice(argv[0], 0, endingIndex), ending);
    printDirectory(path);
  } else {
    printf ("my program can't list the content of multiple folders at once \n");
  }
  return 0;
}