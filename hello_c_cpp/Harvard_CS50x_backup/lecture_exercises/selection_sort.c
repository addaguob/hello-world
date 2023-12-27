#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int numbers[] = {7, 2, 5, 4, 1, 6, 0, 3};
    int len = 8;

    for (int i = 0; i < len; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");

    // O(n²) Ω(n²) Θ(n²)
    // for i from 0 to -1
    //      find smallest number between numbers[i] and numbers[n-1]
    //      swap smallest with number[i]
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
            }
         }
         numbers[i] = smallest;
    }

    for (int i = 0; i < len; i++)
    {
        printf("%i ", numbers[i]);
    }
}
