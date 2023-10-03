#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./casesar key\n");
        return 1;
    }

    int arglen = strlen(argv[1]);
    for (int i = 0; i < arglen; i++)
    {
        if (argv[1][i] < 48 || argv[1][i] > 57)
        {
            printf("Usage: ./casesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);
    string plaintext = get_string("Plaintext: ");
    int ptlen = strlen(plaintext);
    int cypher = 0;
    const int lowercase = 97;
    const int uppercase = 65;

    printf("ciphertext: ");

    for (int i = 0; i < ptlen; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                cypher = (((plaintext[i] - uppercase + key) % 26) + uppercase);
            }
            else
            {
                cypher = (((plaintext[i] - lowercase + key) % 26) + lowercase);
            }
            printf("%c", cypher);
        }
        else
            printf("%c", plaintext[i]);
    }
    printf("\n");
    return 0;
}