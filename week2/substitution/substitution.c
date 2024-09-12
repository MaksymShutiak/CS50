#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int validate_key(string key);
int rotate(char c, string key);
string lower_key(string key);

int main(int argc, string argv[]) 
{
    if (argc != 2 || validate_key(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string text = get_string("Enter string: ");

    printf("ciphertext: ");

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        printf("%c", rotate(text[i], argv[1]));
    }

    printf("\n");

    return 0;
}

int rotate(char c, string key)
{
    char initial_symbol = 'a';

    if (!isalpha(c)) 
    {
        return c;
    }
    if (isupper(c)) 
    {
        initial_symbol = 'A';
        return (char) toupper(key[(c - initial_symbol)]);
    } 

    return (char) tolower(key[(c - initial_symbol)]);
}

int validate_key(string key)
{ 
    int length = strlen(key);

    for (int i = 0; i < length; i++)
    {
        for (int c = 0; c < length; c++)
        {
            if (toupper(key[i]) == toupper(key[c]) && i != c)
            {
                return 1;
            }
        }
        if (isdigit(key[i]) || !isalpha(key[i]))
        {
            return 1;
        }
    }

    return 0;
}

string lower_key(string key)
{
    for (int i = 0, length = strlen(key); i < length; i++)
    {
        key[i] = tolower(key[i]);
    }

    return key;
}
