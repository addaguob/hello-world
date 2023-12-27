#include <cs50.h>
#include <stdio.h>

int sum_long_int(long int ln);

int main(void)
{
    long int ln = get_int("Enter long integer: ");
    printf("Sum is %i\n", sum_long_int(ln));
}

int sum_long_int(long int ln)
{
    int sum = 0;
    if (ln > 0)
    {
        printf("%li\n", ln);

        sum = (ln % 10) + sum_long_int(ln / 10);
    }
    return sum;
}
