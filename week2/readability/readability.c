#include <cs50.h>
#include <math.h>  
#include <stdio.h>
#include <string.h>

int main(void) 
{
    string test = get_string("Text: ");

    float words_count = 0;
    float char_count = 0;
    float sentence_count = 0;

    for (int c = 0; c < strlen(test); c++) 
    {
        if ((test[c] >= 65 && test[c] <= 90) || (test[c] >= 97 && test[c] <= 122))
        {
            char_count += 1;
        }
        if (((test[c] >= 65 && test[c] <= 90) || (test[c] >= 97 && test[c] <= 122)) && 
            (test[c + 1] == 32 || test[c + 1] == 44 || test[c + 1] == 46 || test[c + 1] == 33 || 
             test[c + 1] == 34 || test[c + 1] == 59 || test[c + 1] == 58 || test[c + 1] == 63))
        {
            words_count += 1;
        }
        if (((test[c] >= 65 && test[c] <= 90) || (test[c] >= 97 && test[c] <= 122) || 
             test[c] == 32) && 
            (test[c + 1] == 46 || test[c + 1] == 33 || test[c + 1] == 63))
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
