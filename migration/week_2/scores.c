#include <cs50.h>
#include <stdio.h>


float average(int lenght, int array[]);

int main(void)
{
    int TOTAL = get_int("Total numbers of scores: ");
    
    int scores[3];
    for (int i = 0; i < TOTAL; i++)
    {
        scores[i] = get_int("Score: ");
    }
        
    printf("Average: %f\n", average(TOTAL, scores));
}

float average(int lenght, int array[])
{
    int sum = 0;
    for (int i = 0; i < lenght; i++)
    {
        sum += array[i];
    }
    return(sum / (float) lenght);
}
