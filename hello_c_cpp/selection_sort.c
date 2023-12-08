#include <stdio.h>
#include <cs50.h>
// I want to try sorting some numbers before Prof. David reveals his own code
// O(n²)
int main(void)
{
    int numbers[] = {7, 2, 5, 4, 1, 6, 0, 3};
    int len = 8;

    for (int i = 0; i < len; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
    // for i from 0 to -1
    //      find smallest number between numbers[i] and numbers[n-1]
    //      swap smallest with number[i]
    int process_count = 0;
    for (int i = 0; i < len; i++)
    {
        int smallest = numbers[i];
        for (int j = i, tmp; j < len; j++)
        {
            if (numbers[j] < smallest)
            {
                tmp = smallest;
                smallest = numbers[j];
                numbers[j] = tmp;
                process_count++;
            }
         }
         numbers[i] = smallest;
    }

    for (int i = 0; i < len; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\nProcess count: %i\n", process_count);
}
