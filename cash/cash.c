#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);

int main(void)
{
     // Prompt the user for change owed, in cents
    int cents;
    do
    {
        printf("Type a change >0\n");
        cents = get_int("Change owed: ");
    }
    while (cents <0);

    // Calculate how many quarters you should give customer
    int quarters = calculate_quarters(cents);

    // Subtract the value of those quarters from cents
    cents = cents - (quarters * 25);

    // Calculate how many dimes you should give customer
    // Subtract the value of those dimes from remaining cents

    // Calculate how many nickels you should give customer
    // Subtract the value of those nickels from remaining cents

    // Calculate how many pennies you should give customer
    // Subtract the value of those pennies from remaining cents

    // Sum the number of quarters, dimes, nickels, and pennies used
    // Print that sum
}

int calculate_quarters(int cents)
{
    // Calculate how many quarters you should give customer
    int quarters = 0;
    while (cents >= 25)
    {
        quarters++;
        cents = cents - 25;
    }
    return quarters;
}
