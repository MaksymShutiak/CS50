#include <cs50.h>
#include <stdio.h>

int get_number_digit_sum(int number);
bool is_credit_card_type_visa(int first_digit, int length);
bool is_credit_card_type_mastercard(int first_digit, int second_digit, int length);
bool is_credit_card_type_amex(int first_digit, int second_digit, int length);

int main(void)
{
    long card_number = get_long("Credit card: ");
    int card_number_length = 0;

    int card_luhn_sum = 0;
    long card_number_divider = 1;
    long card_number_saved = card_number;

    while (card_number_saved != 0)
    {
        int current_number = card_number_saved % 10;
        card_number_saved = card_number_saved / 10;
        card_number_divider = card_number_divider * 10;

        if ((card_number_length + 1) % 2 == 0) 
        {
            if ((current_number * 2) >= 10) 
            {
                card_luhn_sum = card_luhn_sum + get_number_digit_sum(current_number * 2);
            } 
            else 
            {
                card_luhn_sum = card_luhn_sum + (current_number * 2);
            }
        } 
        else 
        {
            card_luhn_sum = card_luhn_sum + current_number;
        }
        card_number_length++;
    }

    int credit_card_first_digit = card_number / (card_number_divider / 10);
    int credit_card_second_digit = (card_number / (card_number_divider / 100)) % 10; 

    if (card_number_length > 16 || card_number_length < 13)
    {
        printf("%s\n", "INVALID");
        return 0;
    }

    if (is_credit_card_type_visa(credit_card_first_digit, card_number_length) &&
        card_luhn_sum % 10 == 0)
    {
        printf("%s\n", "VISA");
    }

    else if (is_credit_card_type_mastercard(credit_card_first_digit, credit_card_second_digit, 
                                            card_number_length) && 
             card_luhn_sum % 10 == 0) 
    {
        printf("%s\n", "MASTERCARD");
    }

    else if (is_credit_card_type_amex(credit_card_first_digit, credit_card_second_digit, 
                                      card_number_length) && 
             card_luhn_sum % 10 == 0) 
    {
        printf("%s\n", "AMEX");
    }

    else 
    {
        printf("%s\n", "INVALID");
    }
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
