#include <stdio.h>

int main(void)
{
    int arr[4][3] = {
        {0, 0, 0},
        {1, 1, 1},
        {2, 2, 2},
        {3, 3, 3},
    };

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%i ", arr[i][j]);
        }
        printf("\n");
    }
}
