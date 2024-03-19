#include <cs50.h>
#include <stdio.h>

int get_user_cents_count();
int calculate_coins(int cents, int step);
int calculate_coins_left(int cents, int coins, int step);

int QUARTER_STEP = 25;
int DIMMES_STEP = 10;
int NICKELS_STEP = 5;
int PENNIES_STEP = 1;

int main(void)
{
    int cents = get_user_cents_count();

    int quarters = calculate_coins(cents, QUARTER_STEP);
    cents = calculate_coins_left(cents, quarters, QUARTER_STEP);

    int dimmes = calculate_coins(cents, DIMMES_STEP);
    cents = calculate_coins_left(cents, dimmes, DIMMES_STEP);

    int nickels = calculate_coins(cents, NICKELS_STEP);
    cents = calculate_coins_left(cents, nickels, NICKELS_STEP);

    int pennies = calculate_coins(cents, PENNIES_STEP);
    cents = calculate_coins_left(cents, pennies, PENNIES_STEP);

    int coins = quarters + dimmes + nickels + pennies;

    printf("%i\n", coins);
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

int calculate_coins(int cents, int step)
{
    int coins = 0;
    while (cents >= step)
    {
        coins++;
        cents = cents - step;
    }

    return coins;
}

int calculate_coins_left(int cents, int coins, int step)
{
    return cents - (coins * step);
}
