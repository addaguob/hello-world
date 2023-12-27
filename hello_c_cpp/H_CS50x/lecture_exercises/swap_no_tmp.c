#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Input number for each variable below:\n");


    int a = get_int("a: ");
    int b = get_int("b: ");

    a = a + b;
    b = a - b;
    a = a - b;

    printf("Swapping...\na: %i\nb: %i\n", a, b);
}
