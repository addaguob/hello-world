#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size
    int start_size;
    do
    {
        start_size = get_int("Enter start size: ");
    }
    while (start_size < 9);

    // Prompt for end size
    int end_size;
    do
    {
        end_size = get_int("Enter end size: ");
    }
    while (end_size < start_size);

    // Calculate number of years until we reach threshold
    int current_population = start_size;
    int years_to_reach_end_size = 0;
    while (current_population < end_size)
    {
        int born_per_year = current_population / 3;
        int died_per_year = current_population / 4;
        current_population += (born_per_year - died_per_year);
        years_to_reach_end_size++;
    }

    // Print number of years
    printf("Years: %i\n", years_to_reach_end_size);
}
