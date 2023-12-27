#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;

    do
    {
        height = get_int("Enter height: ");
    }
    while (height < 1 || height > 8);
    // printf("You entered: %i\n", height);
    int spaces = height - 1;
    for (int current_line = 1; current_line <= height; current_line++, spaces--)
    {
        // Left spaces
        for (int space = 1; space <= spaces; space++)
        {
            printf(" ");
        }

        // Left hash
        for (int left_hash = 1; left_hash <= current_line; left_hash++)
        {
            printf("#");
        }

        // Two-space gap
        printf("  ");

        // Right hash
        for (int right_hash = 1; right_hash <= current_line; right_hash++)
        {
            printf("#");
        }
        // New line after each line
        printf("\n");
    }
}