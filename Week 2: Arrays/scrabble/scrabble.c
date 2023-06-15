#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// ASCII values for upercase letters
int uc_letters[] = {65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90};

// ASCII values for lowercase letters
int lc_letters[] = {97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122};

int temp_point[] = {};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int score = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i]))
        {
            for (int j = 0; j < sizeof(uc_letters); j++)
            {
                if (word[i] == uc_letters[j])
                {
                    temp_point[i] = POINTS[j];
                    score += temp_point[i];
                }
            }
        }
        else if (islower(word[i]))
        {
            for (int k = 0; k < sizeof(lc_letters); k++)
            {
                if (word[i] == lc_letters[k])
                {
                    temp_point[i] = POINTS[k];
                    score += temp_point[i];
                }
            }
        }
        else
        {
            i++;
        }
    }

    return score;
}