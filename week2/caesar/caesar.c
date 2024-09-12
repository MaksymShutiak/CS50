#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rotate(char c, int key);
int validate_key(string key);

int main(int argc, string argv[])
{
    if (argc != 2 || validate_key(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string text = get_string("Enter string: ");

    printf("ciphertext: ");

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        printf("%c", rotate(text[i], atoi(argv[1])));
    }

    printf("\n");

    return 0;
}

int rotate(char c, int key)
{
    char initial_symbol = 'a';

    if (!isalpha(c)) 
    {
        return c;
    }
    if (isupper(c)) 
    {
        initial_symbol = 'A';
    }

    return (char) initial_symbol + (c - initial_symbol + key) % 26;
}

int validate_key(string key)
{
    for (int i = 0, length = strlen(key); i < length; i++)
    {
        if (!isdigit(key[i]))
        {
            return 1;
        }
    }

    return 0;
}
