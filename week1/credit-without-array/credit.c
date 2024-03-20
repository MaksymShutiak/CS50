#include <cs50.h>
#include <stdio.h>

int get_number_digit_sum(int number);
int get_array_from_number(long number, int number_length);
bool is_credit_card_type_visa(int first_digit, int length);
bool is_credit_card_type_mastercard(int first_digit, int second_digit, int length);
bool is_credit_card_type_amex(int first_digit, int second_digit, int length);

int main(void)
{
    long credit_card_number = get_long("Credit card: ");
    long local_credit_card_number = credit_card_number;
    int credit_card_length = 0;

    long number_local = credit_card_number;
    int credit_card_luhn_sum = 0;
    int current_number = 0;
    long number_length = 1;

    while (local_credit_card_number != 0)
    {
        current_number = local_credit_card_number % 10;
        local_credit_card_number = local_credit_card_number / 10;
        number_length = number_length * 10;

        if ((credit_card_length + 1) % 2 == 0) {
          if ((current_number * 2) >= 10) {
            credit_card_luhn_sum = credit_card_luhn_sum + get_number_digit_sum(current_number * 2);
          } else {
            credit_card_luhn_sum = credit_card_luhn_sum + (current_number * 2);
          }
        } else {
          credit_card_luhn_sum = credit_card_luhn_sum + current_number;
        }
        credit_card_length++;
    }

    int credit_card_first_digit = credit_card_number / (number_length / 10);
    int credit_card_second_digit = (credit_card_number / (number_length / 100)) % 10; 

    if (credit_card_length > 16 || credit_card_length < 13)
    {
        printf("%s\n", "INVALID");
        return 0;
    }

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
