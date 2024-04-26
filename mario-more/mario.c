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
}


