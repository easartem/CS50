from cs50 import get_int

def main():
    print("entered")
    answer = get_int("Height: ")
    while((answer <= 0) | (answer > 8)):
        answer = get_int("Height: ")

main()
