#include <stdio.h>
#include <cs50.h>
// I want to try sorting some numbers before Prof. David reveals his own code
int main(void)
{
    int array_int[] = {7, 2, 5, 4, 1, 6, 0, 3};
    int array_len = 8;

    for (int i = 0; i < array_len; i++)
    {
        printf("%i ", array_int[i]);
    }
    printf("\n");
    int process_count = 0;
    for (int i = 0; i < array_len; i++)
    {
        for (int j = i+1, tmp_int; j < array_len; j++)
            if (array_int[i] > array_int[j])
            {
                tmp_int = array_int[i];
                array_int[i] = array_int[j];
                array_int[j] = tmp_int;
                process_count++;
            }
    }

    for (int i = 0; i < array_len; i++)
    {
        printf("%i ", array_int[i]);
    }
    printf("\nProcess count: %i.\n", process_count);
}