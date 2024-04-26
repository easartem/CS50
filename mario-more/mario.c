#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int input = -1;
    do
    {
        input = get_int("Height : ");
        printf("Type a number between 1 and 8 included\n");
    }
    while (input < 1 || input > 8);

    for (int i=0; i<input; i++)
    {
        for (int j=0; j<input; j++)
        {
            j equal number of #
            int blank = input - j
            int block = j
            printf(" ")
        }
    }
}


