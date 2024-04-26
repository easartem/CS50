#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int input = get_int("Enter your name : ");
    printf("hello, %s\n", input);
}
