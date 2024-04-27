#include <stdio.h>
#include <cs50.h>

void print_row(int bricks, int blank);

int main(void)
{
    int input;
    do
    {
        printf("Type a number between 1 and 8 included\n");
        input = get_int("Height : ");
    }
    while (input < 1 || input > 8);


    // Print a pyramid of that height
    for (int i = 0; i < input; i++)
    {
        int blank = input - (i+1);
        int bricks = i + 1;
        // Print row of bricks
        print_row(bricks, blank);
    }
}

void print_row(int bricks, int blank)
{
    for (int i = 0; i < blank; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}

