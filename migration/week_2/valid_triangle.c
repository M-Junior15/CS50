#include <cs50.h>
#include <stdio.h>


bool valid_triangle(int a, int b, int c);

int main(void)
{
    int num1, num2, num3;
    
    num1 = get_int("Enter the first value: ");
    num2 = get_int("Enter the second value: ");
    num3 = get_int("Enter the third value: ");
    
    bool valid = valid_triangle(num1, num2, num3);
    
    printf("%i %i %i Make a triangle? %d\n", num1, num2, num3, valid);
}


bool valid_triangle(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0 )
    {
        return false;
    }
    if ((a + b < c) || (a + c < b) || (b + c < a))
    {
        return false;
    }
    
    return true;
}
