#include <cs50.h>
#include <stdio.h>

void print_row(int bricks, int blank);

int main(void)
{
    int input1;
    int input2;
    do
    {
        input1 = get_s("Player 1: ");
        input2 = get_int("Player 2: ");
    }
    while (input < 1 || input > 8);
}
