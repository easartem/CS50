#include <cs50.h>
#include <stdio.h>

int main(void)
{
    do
    {
        int input = get_int("Height : ");
        printf("hello, %d\n", input);
    }
    while ((input >= 1) && (input <= 8));
}
