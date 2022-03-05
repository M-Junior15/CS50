#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int sum = 0, val;
    string copy[26];
    
    val = strlen(argv[1]);

    if (argc == 2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {

            if (val != 26)
            {
                printf("Key must contain 26 characters.\n");

                return 1;
            }

            if (isalpha(argv[1][i]) == false)
            {
                printf("Key must only contain alphabetic characters.\n");
                
                return 1;
                
            }
            
            if (isalpha(argv[1][i]))
            {
                copy[i] = argv[1][i];
                
                return 1;
            }
        }
    }
    else
    {
        printf("Usage: ./substitution key");
    }
}