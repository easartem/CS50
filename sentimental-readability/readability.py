from cs50 import get_int

def main():
    # Prompt the user for some text
    text = get_int("Text: ")

    # Compute L and S for the Coleman-Liau index
    L = (count_letters(text) / (float) count_words(text)) * 100
    S = (count_sentences(text) / (float) count_words(text)) * 100

    # Compute the Coleman-Liau index
    index = 0.0588 * L - 0.296 * S - 15.8
    # Print the grade level by rounding the result
    int result = round(index)
    if (index < 1):
    {
        printf("Before Grade 1")
    }
    elif (index >= 16):
    {
        printf("Grade 16+")
    }
    else:
    {
        printf("Grade %i", result)
    }

def count_letters(string text)
    int len = strlen(text)
    int count = 0
    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            count++
        }
    }
    return count

main()


