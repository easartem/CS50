#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int input;
    do
    {
        input = get_int("Height : ");
        printf("Type a number between 1 and 8 included\n");
    }
    while (input < 1 || input > 8);

    for (int i=input; i>0; i--)
    {
        if(i<)
        {
            printf(" ")
        }
        else
        {
            printf("#")
        }
        printf("\n");
    }

    // Print a pyramid of that height
    for (int i = 0; i < n; i++)
    {
        // Print row of bricks
        print_row(i + 1);
    }
}

void print_row(int bricks)
{
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}

