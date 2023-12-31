#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;

    //checks if n is between 1 and 8 after get n
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    //create n lines
    for (int i = 0; i < n; i++)
    {
        //print first part of #
        for (int j = n - 1; j >= i; j--)
        {
            //print white spaces
            if (j > i)
            {
                printf(" ");
            }

            //print # diagonal
            if (j == i)
            {
                printf("#");

                //print # in the remaining spaces
                for (int a = i; a > 0; a--)
                {
                    printf("#");
                }
            }
        }

        printf("  ");

        //print second part of #
        for (int b = 0; b <= i; b++)
        {
            printf("#");
        }

        printf("\n");
    }
}