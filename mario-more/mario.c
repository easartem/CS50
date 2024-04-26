#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int input = 10;
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
            char test[size];
            test[0] = ' ';
            if (j <= (i+1))
            {
                test = strcopy(test, "#");
            }
            else if (j > (i+1))
            {
                test = strcopy(test, " ");
            }

            char reverse[input+1] =  "";
            for(int k = 0; k < (input+1); k++)
            {
                reverse[k] = test[input - k];
            }
            char result[size] = strcpy(result, test);
            char result[size] = strcpy(result, reverse);
            printf(%s, result)
        }
        printf("\n");
    }
}


