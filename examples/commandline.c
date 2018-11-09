/**
 * Try running with various command line args:
 *
 * ./commandline hello world
 // 3 cmdline args
 * ./commandline this is a test
 // 5 cmdline args
 * ./commandline
 // 1 cmdline arg
 */ 

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