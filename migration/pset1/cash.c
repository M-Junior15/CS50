#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float n; //
    int dollars, sum = 0;
    do
    {
        n = get_float("Change owed: "); //get float number
    }
    while (n <= 0); //get only positive numbers

    dollars = round(n * 100); //convert to integer
    
    while (dollars >= 25) //while the dollars is greater than 25
    {
        sum++; //"sum" receive one more
        dollars = dollars - 25; //dollars decreases 25
    }

    while (dollars >= 10)
    {
        sum++;
        dollars = dollars - 10;
    }
    
    while (dollars >= 5)
    {
        sum++;
        dollars = dollars - 5;
    }
    
    while (dollars >= 1)
    {
        sum++;
        dollars = dollars - 1;
    }
    
    printf("%i\n", sum); //print the total of coins
}