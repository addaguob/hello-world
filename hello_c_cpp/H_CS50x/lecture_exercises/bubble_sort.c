#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[] = {7, 2, 5, 4, 1, 6, 0, 3};
    int len = 8;

    for (int i = 0; i < len; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
    // O(n²) Ω(n)
    // repeat n-1 times
    //      for i from 0 to n-2
    //          if numbers[i] and numbers[i+1] unsorted
    //          swap them

    int process_count = 0;
    for (int i = 0; i < len; i++)
    {
        int swap_occured = 0;
        for (int j = 0, tmp; j < len - 1; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                tmp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = tmp;
                swap_occured++;
            }
        }

        for (int k = 0; k < len; k++)
        {
            printf("%i ", numbers[k]);
        }
        printf("\n");

        if (swap_occured == 0)
            break;
    }
    return 0;
}
