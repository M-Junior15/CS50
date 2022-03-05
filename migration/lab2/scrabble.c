#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1,
                4, 2, 4, 1 ,8,
                5, 1, 3, 1, 1,
                3, 10, 1, 1, 1,
                1, 4, 4, 8, 4, 10};

int computer_science(string word); // Prototype

int main(void)
{

    string word1, word2; // Declare 2 string variables
    int score1, score2; // Declare 2 integer variables
    
    // Get 2 values for both strings
    word1 = get_string("Player1: ");
    word2 = get_string("Player2: ");

    // Score both words
    score1 = computer_science(word1);
    score2 = computer_science(word2);

    // Print the winner
    if (score1 > score2) // If score1 is greater than score2
    {
        printf("Player 1 wins!\n"); 
    }
    else if(score2 > score1) // Else if score2 is greater than 1
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

}

// Declare the function
int computer_science(string word)
{
    int sum = 0;
    
    // Make a loop to see every letter in the word 
    for (int i = 0, n = strlen(word); i < n; i++)
    {

        word[i] = toupper(word[i]); // The letter in the position "i" capitalize

        if ( word[i] >= 65 && word[i] <= 90) // If the letter i position "i" is greater than 65 AND lower than 90
        {   
            
            word[i] = POINTS[word[i]-65]; // The letter in the position "i" receive POINTS in the position "word[i] - 65"
            
            sum += word[i]; 
        }
    }
    return (sum);
}
