from cs50 import get_float


def main():
    # Get the desired amount
    answer = get_float("Change: ")
    while (answer < 0):
        answer = get_float("Change: ")

    #

    # Construct the pyramide
    for i in range(1, answer+1):
        print(" "*(answer-i), end="")
        print("#"*i, end="")
        print(" "*2, end="")
        print("#"*i)


main()
