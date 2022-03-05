#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int check_letter_word_sentence(string phrase); // Prototype

int main(void)
{
    // Variables
    string text;
    int values;
    
    text = get_string("Text: ");
    
    values = check_letter_word_sentence(text); // Values receive function "check_letter_word_sentence"

    // Infinite while loop conditions to print the grade
    while (true)
    {
        if (values <= 1)
        {
            printf("Before Grade 1\n");
            break;
        }
        
        else if (values > 1 && values <= 16)
        {
            printf("Grade %i\n", values);
            break;
        }
        
        else
        {
            printf("Grade 16+\n");
            break;
        }
    }
    
}

// Declared function
int check_letter_word_sentence(string phrase)
{
    // Local variables
    int letter = 0, word = 1, sentence = 0;
    double index;
    
    // For loop to get every word in the "PHRASE"
    for (int i = 0, n = strlen(phrase); i < n; i++)
    {
        phrase[i] = toupper(phrase[i]); // Captilize the words of "PHRASE"
        
        if (phrase[i] >= 65 && phrase[i] <= 90) // If the words is greater than 65 and lower than 90
        {
            letter++;
        }   
        else if (phrase[i] == ' ') // If have space in the phrase
        {
            word++;
        }
        else if (phrase[i] == '.' || phrase[i] == '!' || phrase[i] == '?') // If "PHRASE[i]" = "." or "!" or "?" ? 
        {
            sentence++;
        }
    }    
    
    
    index = 0.0588 * letter / word * 100 - 0.296 * sentence / word * 100 - 15.8; // Coleman Liau formula
    return round(index);
}
