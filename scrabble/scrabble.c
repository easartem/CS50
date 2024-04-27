#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int compute_score(string word);

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10, 0};
char ALPHABET[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};


int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Compute the score of each word
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 == score2)
    {
        printf("Tie!");
    }
    else if (score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else
    {
        printf("Player 2 wins!");
    }
    printf("\n");
}


int compute_score(string word)
{
    int score = 0;
    int lenword = strlen(word);
    for (int i=0 ; i<lenword ; i++)
    {
        word[i] = tolower(word[i]);
    }

    // Compute and return score for word
    for (int j=0 ; j<lenword ; j++)
    {
        int index = -1;
        do
        {
            index++;
            // printf("word: %c", word[index])
            // printf("alphabet: %c", ALPHABET[index])
            if (index == 26)
            {
                break;
            }
        } while(word[j] != ALPHABET[index]);
        score = score + POINTS[index];
    }
    return score;
}
