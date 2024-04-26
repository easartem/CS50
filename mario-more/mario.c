#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int input = -1;
    do
    {
        input = get_int("Height : ");
        printf("hello, %d\n", input);
    }
    while (input < 1 && input > 8);
}


