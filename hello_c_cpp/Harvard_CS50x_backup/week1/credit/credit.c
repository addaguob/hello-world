
/*
American Express uses 15-digit numbers,
MasterCard uses 16-digit numbers, and
Visa uses 13- and 16-digit numbers
---
American Express numbers start with 34 or 37; most
MasterCard numbers start with 51, 52, 53, 54, or 55 and all
Visa numbers start with 4
*/
#include <cs50.h>
#include <stdio.h>

int sum_long_int(long card_numbers);
void checksum(long card_numbers);

int main(void)
{
    long card_numbers;

    do
    {
        card_numbers = get_long("Number: ");
    }
    while (card_numbers < 0);
    checksum(card_numbers);
}

void checksum(long card_numbers)
{
    int count = 1;
    int even_digit = 0;
    int even_sum = 0;
    int final_zero = 1;
    int len = 0;
    int odd_digit = 0;
    int odd_sum = 0;
    long first_two_digits = card_numbers; // to be reduced later

    while (card_numbers > 0)
    {
        if ((count % 2) == 0) // sum of even digits
        {
            even_digit = (card_numbers % 10);
            even_sum += sum_long_int(even_digit * 2);
            // printf("%i: %i * 2 = %i\n", count, even_digit, (even_digit * 2));
        }
        else
        {
            odd_digit = (card_numbers % 10);
            // printf("%i: %i\n", count, odd_digit);
            odd_sum += odd_digit;
        }

        card_numbers = card_numbers / 10; // remove last digit
        len = count;
        count++;
    }
    final_zero = even_sum + odd_sum;
    // printf("len: %i\n", len);
    // printf("count: %i\n", count);
    // printf("even_sum: %i: odd_sum: %i\n", even_sum, odd_sum);
    // printf("even+odd: %i\n", final_zero);
    if (final_zero % 10 == 0)
    {
        // Check Card Type
        for (int i = 0; i < (len - 2); i++)
        {
            first_two_digits /= 10;
            // printf("first_two_digits: %li\n", first_two_digits);
        }
        // Is it AMEX?
        if (len == 15 && (first_two_digits == 34 || first_two_digits == 37))
            printf("AMEX\n");
        // or MASTERCARD?
        else if (len == 16 && (first_two_digits >= 51 && first_two_digits <= 55))
            printf("MASTERCARD\n");
        // or VISA?
        else if ((len == 13 || len == 16) && (first_two_digits >= 40 && first_two_digits <= 49))
            printf("VISA\n");
        else
            printf("INVALID\n");
    }
    else
        printf("INVALID\n");
}

int sum_long_int(long card_numbers)
{
    int sum = 0;
    if (card_numbers > 0)
        sum = (card_numbers % 10) + sum_long_int(card_numbers / 10);
    return sum;
}
