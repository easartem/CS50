from cs50 import get_string
import re


def main():
    # Prompt the user for some text
    text = get_string("Text: ")

    # Compute L and S for the Coleman-Liau index
    L = (count_letters(text) / count_words(text)) * 100
    S = (count_sentences(text) / count_words(text)) * 100

    # Compute the Coleman-Liau index
    index = 0.0588 * L - 0.296 * S - 15.8

    # Print the grade level by rounding the result
    result = round(index)
    if (index < 1):
        print("Before Grade 1")
    elif (index >= 16):
        print("Grade 16+")
    else:
        print("Grade ", result)


def count_letters(text):
    count = 0
    for char in text:
        if (char.isalpha()):
            count += 1
    return count


def count_words(text):
    words = text.split(" ")
    count = len(words)
    return count


def count_sentences(text):
    count = 0
    for char in text:
        if ((char == '.') | (char == '?') | (char == '!')):
            count += 1
    return count


main()
