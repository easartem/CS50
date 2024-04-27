from cs50 import get_string

def main():
    # Prompt the user for some text
    text = get_string("Text: ")

    # Compute L and S for the Coleman-Liau index
    # L = (count_letters(text) / (float) count_words(text)) * 100
    # S = (count_sentences(text) / (float) count_words(text)) * 100
    print(count_words(text))
    # Compute the Coleman-Liau index
    # index = 0.0588 * L - 0.296 * S - 15.8
    index = 4
    # Print the grade level by rounding the result
    result = round(index)
    if (index < 1):
        print("Before Grade 1")
    elif (index >= 16):
        print("Grade 16+")
    else:
        print("Grade ", result)

def count_words(text):
    words = text.split(" ")
    count = len(words)
    return count

main()


