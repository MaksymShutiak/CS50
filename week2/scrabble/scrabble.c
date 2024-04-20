#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int get_winner_index(int players_score[], int players_count);
int calculate_score_for_player(string word);

//                      A  B  C  D   E  F  G  H  I  J  K  L  M 
int SCORE_POINTS[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
//                      N  O  P  Q   R  S  T  U  V  W  X  Y  Z
                        1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{

    int players_count = 2;
    int players_score[players_count];
    string players_words[players_count]; 

    for (int i = 0; i < players_count; i++)
    {
        players_words[i] = get_string("Player %i: ", i + 1);     
        players_score[i] = calculate_score_for_player(players_words[i]);
    }
    
    int winner_index = get_winner_index(players_score, players_count);

    if (winner_index > 0)
    {
        printf("Player %i wins \n", winner_index);
    }
    else
    {
        printf("Tie!\n");
    }
}

int get_winner_index(int players_score[], int players_count)
{
    int higest_score = 0;
    int winner_index;

    for (int i = 0; i < players_count; i++)
    {
        if (higest_score < players_score[i])
        {
            higest_score = players_score[i];
            winner_index = i + 1;
        } 
        else if (higest_score == players_score[i]) 
        {
            winner_index = 0;
        }
    }

    return winner_index;
}

int calculate_score_for_player(string word)
{
    int score = 0;

    for (int w = 0; w < strlen(word); w++) 
    {
        char currentWordSymbol = word[w];

        if (isupper(currentWordSymbol))
        {
            score += SCORE_POINTS[currentWordSymbol - 'A'];
        }
        else if (islower(currentWordSymbol))
        {
            score += SCORE_POINTS[currentWordSymbol - 'a'];
        }
    }

    return score;
}
