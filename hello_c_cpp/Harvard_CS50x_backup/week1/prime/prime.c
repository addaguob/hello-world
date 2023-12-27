#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    bool i_dunno_yet = false;
    bool is_prime = i_dunno_yet;

    for (int start = number; start > 1; start--)
    {
        // Check if number is divisble only by itself or by 1
        if (number % number == 0 && number % 1 == 0)
        {
            is_prime = true;
        }
        // Check below number and above 1 if there's an integer other than them...
        if (number % start == 0 && start > 1 && start < number) // ... that has zero remainder
        {
            is_prime = false;
            break; // We don't need to finish the loop, the evidence would be clear.
        }
    }
    return is_prime;
}
