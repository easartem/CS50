from cs50 import get_int

def main():
    # Get the desired height
    print("entered")
    answer = get_int("Height: ")
    while((answer <= 0) | (answer > 8)):
        answer = get_int("Height: ")

    # Construct the pyramide
    for i in range(answer):
        for j in range(answer):
            print(" "*(answer-i), end="")
            print("#"*i, end="")
main()
