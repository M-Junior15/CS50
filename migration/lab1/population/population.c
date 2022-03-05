#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Declare the start and the end size.
    int s_size, e_size; 
    
    // n = number of years.
    int n = 0;
    
    // Get the initial population size.
    do
    {
        s_size = get_int("Population size: ");
    }
    while (s_size < 9);
    
    // Get the final population size. 
    do
    {
        e_size = get_int("Ending size: ");
    }
    while (e_size < s_size);
    
    // While start size < end size
    while (s_size < e_size)
    {
        s_size = s_size + (s_size / 3) - (s_size / 4);
            
        // Number of year + 1
        n++;
    }
    
    printf("Years: %i\n", n);
}
