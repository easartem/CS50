#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Enter only the key as argument in the command-line");
        return 1;
    }

    // Make sure every character in argv[1] is a digit
    int len = strlen(argv[1])
    for (int i = 0; i < len; i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./caesar key");
            return 1;
        }
    }

    // Convert argv[1] from a `string` to an `int`

    // Prompt user for plaintext
    string plaintext = get_string("plaintext:  ");
    printf("\n");

    // For each character in the plaintext:

    // Rotate the character if it's a letter

    // Output the result
    printf("plaintext: ", ciphertext);
    printf("\n");
    return 0;
}
