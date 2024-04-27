#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int input;
    do
    {
        printf("Type a change >0\n");
        input = get_int("Change owed: ");
    }
    while (input <=0);
}
