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

    for (int i=0; i<input; i++)
    {
        for (int j=1; j<=input; j++)
        {
            int size = (input+1)*2;
            start by " "
            if (j <= (i+1))
            {
                printf("#");
            }
            else if (j > (i+1))
            {
                printf(" ");
            }
            char start[input+1] =  "";
            char reverse[input+1] =  "";
            for(int k = 0; k < (input+1); k++)
            {
                reverse[ik] = start[input - k];
            }
            char result[size] = strcpy(result, start);
            char result[size] = strcpy(result, reverse);
            printf(%s, result)
        }
        printf("\n");
    }
}


