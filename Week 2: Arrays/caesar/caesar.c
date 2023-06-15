#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char rotate(char c, int n);

int main(int argc, string argv[])
{
    if (argc == 2 && isdigit(*argv[1]))
    {
        for (int k = 0; k < strlen(argv[1]); k++)
        {
            if (!isdigit(argv[1][k]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        int i = atoi(argv[1]);

        if (i <= 0)
        {
            printf("Usage: ./caesar key\n");
            return 0;
        }
        else
        {
            string plaintext = get_string("plaintext: ");

            int n = strlen(plaintext);
            char ciphertext[n];

            printf("ciphertext: ");
            for (int j = 0; j < n; j++)
            {
                ciphertext[j] = rotate(plaintext[j], i);
                printf("%c", ciphertext[j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}


char rotate(char c, int n)
{
    char cipher;

    if (islower(c))
    {
        cipher = (((c + n) - 97) % 26) + 97;
    }
    else if (isupper(c))
    {
        cipher = (((c + n) - 65) % 26) + 65;
    }
    else
    {
        cipher = c;
    }

    return cipher;
}