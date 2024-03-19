#include <cs50.h>
#include <stdio.h>

int get_nubmer_length(long number);
int get_array_from_number(long number, int number_length);
int get_lugn_sum(int array_length, int array[]);
void create_array_for(long number, int *target);
bool is_credit_card_type_visa(int first_digit, int length);
bool is_credit_card_type_mastercard(int first_digit, int second_digit, int length);
bool is_credit_card_type_amex(int first_digit, int second_digit, int length);

int main(void)
{

    long credit_card_number = get_long("Credit card: ");
    int credit_card_length = get_nubmer_length(credit_card_number);

    if (credit_card_length > 16 || credit_card_length < 13)
    {
        printf("%s\n", "INVALID");
        return 0;
    }

    int credit_card_array[credit_card_length];
    create_array_for(credit_card_number, credit_card_array);

    int credit_card_luhn_sum = get_lugn_sum(credit_card_length, credit_card_array);
    int credit_card_first_digit = credit_card_array[credit_card_length - 1];
    int credit_card_second_digit = credit_card_array[credit_card_length - 2]; 

    if (is_credit_card_type_visa(credit_card_first_digit, credit_card_length) &&
        credit_card_luhn_sum % 10 == 0)
    {
        printf("%s\n", "VISA");
    }

    else if (is_credit_card_type_mastercard(credit_card_first_digit, credit_card_second_digit, 
                                            credit_card_length) && 
             credit_card_luhn_sum % 10 == 0) 
    {
        printf("%s\n", "MASTERCARD");
    }

    else if (is_credit_card_type_amex(credit_card_first_digit, credit_card_second_digit, 
                                      credit_card_length) && 
             credit_card_luhn_sum % 10 == 0) 
    {
        printf("%s\n", "AMEX");
    }

    else 
    {
        printf("%s\n", "INVALID");
    }
}

int get_nubmer_length(long number) 
{
    int length = 0;
    long number_local = number;

    while (number_local != 0)
    {
        number_local = number_local / 10;
        length++;
    }

    return length;
}

int get_number_digit_sum(int number)
{
    int num = number, rem, sum = 0;
    while (num != 0)
    {
        rem = num % 10;
        sum = sum + rem;
        num = num / 10;
    }

    return sum;
}

int get_lugn_sum(int array_length, int array[])
{
    int luhn_sum = 0;

    for (int b = 0; b < array_length; b++) 
    {
        if (((b + 1) % 2) == 0 && ((array[b] * 2) >= 10) == 1) 
        {
            int sum = get_number_digit_sum(array[b] * 2);
            luhn_sum = luhn_sum + sum;
        } 
        else if (((b + 1) % 2) == 0 && ((array[b] * 2) > 10) == 0) 
        {
            luhn_sum = luhn_sum + (array[b] * 2);
        } 
        else 
        {
            luhn_sum = luhn_sum + (array[b]);
        }
    }

    return luhn_sum;
}

bool is_credit_card_type_visa(int first_digit, int length) 
{
    return first_digit == 4 && (length == 13 || length == 16);
}

bool is_credit_card_type_mastercard(int first_digit, int second_digit, int length) 
{
    return first_digit == 5 && length == 16 && 
           (second_digit == 1 || second_digit == 2 || second_digit == 3 || second_digit == 4 ||
            second_digit == 5);
}

bool is_credit_card_type_amex(int first_digit, int second_digit, int length) 
{
    return first_digit == 3 && (second_digit == 4 || second_digit == 7) && length == 15;
}

void create_array_for(long number, int *target) 
{
    int index = 0;

    while (number != 0) 
    {
        target[index] = number % 10;
        number = number / 10;
        index++;
    }
}
