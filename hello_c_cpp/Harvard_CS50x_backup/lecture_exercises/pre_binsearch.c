#include <stdio.h>
#include <cs50.h>
// I want to try making a binary search before Prof. David shows me how

int main(void)
{
    int numbers[] = {1, 5, 13, 9, 11, 3, 15, 7, 4, 14, 12, 2, 6, 10, 8};
    int array_length = sizeof(numbers) / sizeof(numbers[0]);

    printf("Pre-set array of integers: %i\n", array_length);
    for (int i = 0; i < array_length; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
    printf("Array length is: %i\n", array_length);

    int search_num = get_int("Enter a number between 0 and 16: ");
    // Sort numbers first
    for(int i = 0; i < array_length; i++)
    {
        for (int j = i+1, iTmp; j < array_length; j++)
        {
            if (numbers[i] > numbers[j])
            {
                iTmp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = iTmp;
            }
        }
    }
    printf("Sorted array of integers: \n");
    for (int i = 0; i < array_length; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
    // Do binary search: display how many checks
    int mid_index = array_length / 2;
    printf("Mid index: %i\n", mid_index);
    int try_count = 0;
    int low_index = 0;
    int high_index = array_length-1;
    do {
        try_count++;
        if (search_num < numbers[mid_index])
        {
            high_index = mid_index;
            mid_index /= 2;
        }
        else if (search_num > numbers[mid_index])
        {
            low_index = mid_index;
            mid_index += (high_index - low_index) / 2 ? (high_index - low_index) / 2 : 1;
        }
        else break;

    } while (search_num != numbers[mid_index]);

    printf("%i is found at index[%i]\n", search_num, mid_index);
    printf("Number of tries: %i\n", try_count);
}