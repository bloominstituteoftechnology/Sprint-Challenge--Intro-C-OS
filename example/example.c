#include <stdio.h>
#include <dirent.h>

void main(int argc, char *argv[])
{
    DIR *dir;
    struct dirent *dent;
    dir = opendir(argv[1]);

    if (dir != NULL)
    {
        while ((dent = readdir(dir)) != NULL)
        {
            if ((strcmp(dent->d_name, ".") == 0 || strcmp(dent->d_name, "..") == 0 || (*dent->d_name) == '.'))
            {
            }
            else
            {
                printf(dent->d_name);
                printf("\n");
            }
        }
    }
    closedir(dir);
}