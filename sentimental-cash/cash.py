from cs50 import get_float


def main():
    # Get the desired amount
    answer = get_float("Change: ")
    while (answer < 0):
        answer = get_float("Change: ")

    # Initialize the change number to 0
    # Calculate how many quarters you should give customer
    quarters = calculate_quarters(cents)
    cents = cents - (quarters * 25);
    # Construct the pyramide
    for i in range(1, answer+1):
        print(" "*(answer-i), end="")
        print("#"*i, end="")
        print(" "*2, end="")
        print("#"*i)


main()


    // Calculate how many quarters you should give customer
    int quarters = calculate_quarters(cents);

    // Subtract the value of those quarters from cents (25c)
    cents = cents - (quarters * 25);

    // Calculate how many dimes you should give customer (10c)
    int dimes = calculate_dimes(cents);
    // Subtract the value of those dimes from remaining cents
    cents = cents - (dimes * 10);
