from cs50 import get_int

def main():
    # Get the desired height
    print("entered")
    answer = get_int("Height: ")
    while((answer <= 0) | (answer > 8)):
        answer = get_int("Height: ")

    # Construct the pyramide
    for i in range(1, answer+1):
        print(" "*(answer-i), end="")
        print("#"*i, end="")
        print(" "*2, end="")
        print("#"*i)
main()
