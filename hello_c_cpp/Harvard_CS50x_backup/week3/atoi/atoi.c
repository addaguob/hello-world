#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    /*
    123
    3 * 1
    2 * 10
    1 * 10 * 10
    */
    int len = strlen(input);
    int intput = 0;

    if (len > 0)
    {
        int last_char = len - 1;
        int last_digit = input[last_char] - '0'; // '0' = ascii 48
        input[last_char] = '\0';
        intput = last_digit + (convert(input) * 10);
    }
    return intput;
}
