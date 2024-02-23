#include <cs50.h>
#include <stdio.h>

int get_user_cents_count();
int calculate_quarters(int cents);

int main(void)
{

    int cents = get_user_cents_count();

    int quarters = calculate_quarters(cents);

    cents = cents - (quarters *  25);

    printf("Quarters: %i\n", cents);
}

int get_user_cents_count()
{

    int min_height = 0;
    int cents;
    do 
    {
        cents = get_int("Change owed: ");
    }

    while (cents < min_height);

    return cents;
}

int calculate_quarters(int cents)
{
    int quarters = 0;
    while (cents >= 25)
    {
        quarters++;
        cents = cents - 25;
    }

    return quarters;
}

int calculate_dimes(int cents)
{

}

int calculate_nickels(int cents)
{

}

int calculate_pennies(int cents)
{

}
