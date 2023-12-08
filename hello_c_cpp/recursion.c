#include <cs50.h>
#include <stdio.h>

void draw(int n);
int fact(int n);
int fibonacci(int n);

int main(void)
{
    int height = get_int("Enter height: ");
    draw(height);
    printf("fact(%i) is %i\n", height, fact(height));
    printf("fibonacci(%i) is %i\n", height, fibonacci(height));
}

void draw(int n)
{
    if (n < 0)
    {
        return;
    }

    draw(n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}

int fact(int n)
{
    if (n == 1) // 1 base case
        return 1;
    else // recursive case
        return n * fact(n - 1);
}

int fibonacci(int n)
{
    if (n == 1)  // dual base case
        return 0;
    else if (n == 2)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int collatz(int n)
{
    
}
