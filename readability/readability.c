#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    // beware cast int to float for division
    float L = (count_letters(text) / (float) count_words(text)) * 100; // average number of letters per 100 words : the number of letters divided by the number of words, all multiplied by 100.
    float S = (count_sentences(text) / (float) count_words(text)) * 100; // average number of sentences per 100 words : the number of sentences divided by the number of words, all multiplied by 100

    // Compute the Coleman-Liau index
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Print the grade level by rounding the resuylt
    int result = round(index);
    if(index < 1)
    {
        printf("Before Grade 1");
    }
    else if (index >= 16)
    {
        printf("Grade 16+");
    }
    else
    {
        printf("Grade %i", result);
    }
}


int count_letters(string text)
{
    int len = strlen(text);
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}


int count_words(string text)
{
    int len = strlen(text);
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }
    return count;
}


int count_sentences(string text)
{
    // Return the number of sentences in text . ! ?
    int len = strlen(text);
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (ispunct(text[i]))
        {
            count++;
        }
    }
    return count;
}
