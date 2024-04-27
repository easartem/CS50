from cs50 import get_float


def main():
    # Get the desired amount
    dollars = get_float("Change: ")
    while (dollars < 0):
        dollars = get_float("Change: ")

    # Initialize the change number to 0
    # Calculate how many coins you should give customer
    print("Initial nb ", dollars)
    quarters, dollars = calculate_cash(dollars, 0.25)
    print("after quarter ", dollars)
    dimes, dollars = calculate_cash(dollars, 0.10)
    print("after dimes ", dollars)
    nickels, dollars = calculate_cash(dollars, 0.05)
    print("after nickels ", dollars)
    pennies, dollars = calculate_cash(dollars, 0.01)
    print("after pennies ", dollars)
    # Sum the number of quarters, dimes, nickels, and pennies used
    sum = 0
    sum = quarters + dimes + nickels + pennies
    print(sum)
    print(quarters)
    print(dimes)
    print(nickels)
    print(pennies)






def calculate_cash(dollars, type):
    nb = 0
    while(dollars >= type):
        nb += 1
        dollars = dollars - type
    return nb, dollars

main()

