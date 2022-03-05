#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Variables
    string plaintext, ciphertext[0];
    int key;

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");

        return 1;
    }

    // Get every word in "argv" and see if is alphabetic
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");

            return 1; // Return 1 (error value)

        }

        key = atoi(argv[1]); // Change argv from "number string" to "number integer"

    }

    plaintext = get_string("Plainext: ");

    // Get length of string "plaintext"
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // Get all value in plaintext and see if is lowercase
        if (islower(plaintext[i]))
        {
            plaintext[i] = plaintext[i] - 97; // Put the plaintext[i] in sequence 0(Aa) to 25(Zz)


            // Formula to return the count to 0, 1, 2... after 25(Zz) and cipher the plaintext with the "key"
            plaintext[i] = (plaintext[i] + key) % 26;

            plaintext[i] = plaintext[i] + 97; // Plaintext + 97 to get the cipher letter
        }

        // Get all value in plaintext and see if is uppercase
        // Repeat the same process of the lowercase
        if (isupper(plaintext[i]))
        {
            plaintext[i] = plaintext[i] - 65;

            plaintext[i] = (plaintext[i] + key) % 26;

            plaintext[i] = plaintext[i] + 65;

        }
    }
    printf("ciphertext: %s\n", plaintext); // Print the ciphertext
}
