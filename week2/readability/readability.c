#include <cs50.h>
#include <math.h>  
#include <stdio.h>
#include <string.h>

int main(void) 
{
    string text = get_string("Text: ");

    float words_count = 0;
    float char_count = 0;
    float sentence_count = 0;

    for (int c = 0; c < strlen(text); c++) 
    {
        if ((text[c] >= 65 && text[c] <= 90) || 
            (text[c] >= 97 && text[c] <= 122))
        {
            char_count += 1;
        }
        if (((text[c] >= 65 && text[c] <= 90) || (text[c] >= 97 && text[c] <= 122)) && 
            (text[c + 1] == 32 || text[c + 1] == 44 || text[c + 1] == 46 || text[c + 1] == 33 || 
             text[c + 1] == 34 || text[c + 1] == 59 || text[c + 1] == 58 || text[c + 1] == 63))
        {
            words_count += 1;
        }
        if (((text[c] >= 65 && text[c] <= 90) || (text[c] >= 97 && text[c] <= 122) || 
             text[c] == 32) && 
            (text[c + 1] == 46 || text[c + 1] == 33 || text[c + 1] == 63))
        {
            sentence_count += 1;
        }
    }

    float grade = 0.0588 * ((char_count / words_count) * 100) - 
                  (0.296 * ((sentence_count / words_count) * 100)) - 15.8;

    printf("Grade %f\n", grade);
    if (grade < 0) 
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else 
    {
        printf("Grade %i\n", (int) round(grade));
    }
}
