#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string user_input = get_string("What's your name ? ");

    printf("hello, %s\n", user_input);
}
