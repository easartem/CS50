from cs50 import get_float


def main():
    # Get the desired amount
    dollars = get_float("Change: ")
    while (dollars < 0):
        dollars = get_float("Change: ")

    # Initialize the change number to 0
    # Calculate how many coins you should give customer
    quarters, dollars = calculate_cash(dollars, 0.25)
    dimes, dollars = calculate_cash(dollars, 0.10)
    nickels, dollars = calculate_cash(dollars, 0.05)
    pennies, dollars = calculate_cash(dollars, 0.01)
    # Sum the number of quarters, dimes, nickels, and pennies used
    sum = 0
    sum = quarters + dimes + nickels + pennies
    print(sum)


def calculate_cash(dollars, type):
    nb = 0
    while(dollars >= type):
        nb += 1
        dollars = dollars - type
    return nb, dollars

main()

