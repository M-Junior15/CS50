#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long n;
    int sum, sum1 = 0, new_n;
    n = get_long("Number: ");
    n = n / 10;
    printf("%li\n", n);

    
    do
    {   
        sum = n % 10 * 2;
        new_n = n / 100;
        sum1 += sum;

    }
    while(n > 1);
    
    printf("%i\n", sum);

}