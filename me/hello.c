#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string input = get_string("Enter your name : ");
    printf("Hello, %s\n", input);
}
