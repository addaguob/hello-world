#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// TODO: complete the calc_hours function
float calc_hours(int hours[], int weeks, char output)
{
    float sum = 0;
    float average = 0;

    // Calculate sum of all array int elements
    for (int i = 0; i < weeks; i++)
    {
        sum += hours[i];
    }
    // Calculate average of sum
    average = sum / weeks;

    if (output == 'T') // Total hours
    {
        return sum;
    }
    return average;
}