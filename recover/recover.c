#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("There can be only one command-line argument.\n");
        return 2;
    }
}
