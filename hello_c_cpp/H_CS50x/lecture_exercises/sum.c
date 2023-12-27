#include <cs50.h>
#include <stdio.h>

int sum_asc(int n);
int sum_desc(int n);

int main(void)
{
    int n = get_int("Enter number: ");
    printf("Sum is %i\n", sum_asc(n));
    printf("Sum is %i\n", sum_desc(n));
}

int sum_asc(int n)
{
    int sum = 0;
    if (n > 0)
    {
        sum = n + sum_asc(n - 1);
        printf("%i\n", n);
    }
    return sum;
}

int sum_desc(int n)
{
    printf("%i\n", n);
    if (n == 1)
        return 1;
    else
        return n + sum_desc(n - 1);
}
