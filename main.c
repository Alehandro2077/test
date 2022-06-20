#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s DIR\n", argv[0]);
        exit(1);
    }

    char *searchf = "find_me";
    exit(walk(argv[1],  1, searchf));
}
