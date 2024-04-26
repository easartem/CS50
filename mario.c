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

    for (int i=0; i<input; i++)
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
}
