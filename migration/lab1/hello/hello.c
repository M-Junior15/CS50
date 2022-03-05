#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get the user name
    string name = get_string("What's your name? ");
    
    // Print the user name
    printf("Hello %s\n", name);
}