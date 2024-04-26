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
        for (int j=1; j<=input; j++)
        {
            int blank = input - j;
            int block = input/2;
            int size = (input+1)*2;
            if (j <= blank)
            {
                printf(" ");
            }
            else if (j == block)
            {
                printf("#");
            }
            else if (j > block && j < (block+2))
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}


