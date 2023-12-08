#include <cs50.h>
#include <stdio.h>
// I want to try sorting some numbers before Prof. David reveals his own code
// n(n-1)/2
int main(void)
{
    int numbers[] = {7, 2, 5, 4, 1, 6, 0, 3};
    int len = 8;

    for (int i = 0; i < len; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
    // repeat n-1 times
    // for i from 0 to n-2
    // if numbers[i] and numbers[i+1] unsorted
    // swap them
    int process_count = 0;
    for (int i = 0; i < len; i++)
    {
        int sorted_count = 0;
        for (int j = 0, tmp; j < len - 1; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                tmp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = tmp;
                process_count++;
            }
            else if (i > (len / 2))
            {
                for (int x = 0; x < len - 1; x++)
                {
                    if (numbers[x] < numbers[x + 1])
                    {
                        sorted_count++;
                        if (sorted_count == len - 2)
                        {
                            i = len;
                            break;
                        }
                    }
                    else
                        break;
                }
            }
        }

        for (int k = 0; k < len; k++)
        {
            printf("%i ", numbers[k]);
        }
        printf("\n");

    }
    printf("\nProcess count: %i\n", process_count);
    return 0;
}
