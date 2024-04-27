#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char rotate(char c, int k);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Enter only the key as argument in the command-line\n");
        return 1;
    }

    // Make sure every character in argv[1] is a digit
    int len = strlen(argv[1]);
    for (int i = 0; i < len; i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);
    printf("The key is : %i\n", key);

    // Prompt user for plaintext
    string plaintext = get_string("plaintext:  ");

    // For each character in the plaintext:
    int size = strlen(plaintext);
    printf("ciphertext: ");
    for (int i = 0; i < size; i++)
    {
        printf("%i", rotate(plaintext[i], key));
    }
    // Rotate the character if it's a letter
    // Output the result
    //printf("plaintext: %s", ciphertext);
    printf("\n");
    return 0;
}

char rotate(char p, int k)
{
    char c;
    printf("The char %c is %i \n", p, p);
    if (isalpha(p))
    {
        if (isupper(p))
        {
            int p_new = (int) p - 'A';
            c = (p_new + k) % 26;
            return (char) c;
        }
        if (islower(p))
        {
            int p_new = (int) p - 'a';
            c = (p_new + k) % 26;
            return (char) c;
        }
    }
    else
    {
        return p;
    }
}
