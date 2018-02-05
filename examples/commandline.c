// gcc -Wall -Wextra -o commandline commandline.c
 
#include <stdio.h>

int main(int argc, char **argv)
{
    int i;

    printf("There are %d command line argument(s):\n", argc);

    for (i = 0; i < argc; i++) {
        printf("   %s\n", argv[i]);
    }

    return 0;
} 