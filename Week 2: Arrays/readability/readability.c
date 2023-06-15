#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int  main(void)
{

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

    string userInput = get_string("Text: ");
    int letters = count_letters(userInput);
    int words = count_words(userInput);
    int sentences = count_sentences(userInput);
    double L = (double) letters / words * 100;
    double S = (double) sentences / words * 100;
    int index = round(((0.0588 * L) - (0.296 * S) - 15.8));
    if (index >= 1 && index <= 16)
    {
        printf("Grade %i\n", index);
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text)
{
    int chars = 0;
    for (int i = 0 ; text[i] != '\0' ; i++)
    {
        if (((int) text[i] >= 65 && (int) text[i] <= 90) || ((int) text[i] >= 97 && (int) text[i] <= 122))
        {
            chars++;
        }
    }
    return chars;
}

int count_words(string text)
{
    int word = 0;
    for (int i = 0 ; text[i] != '\0' ; i++)
    {
        if ((int) text[i] == 32)
        {
            word++;
        }
    }
    word++;
    return word;
}

int count_sentences(string text)
{
    int sent = 0;
    for (int i = 0 ; text[i] != '\0' ; i++)
    {
        if ((int) text[i] == 33 || (int) text[i] == 46 || (int) text[i] == 63)
        {
            sent++;
        }
    }
    return sent;
}