#include <stdio.h>
// Just to see array manipulation via function
void reverse(int arr[], int len);
void swap(int* n1, int* n2);

int main(void)
{
    int arr[4] = {1, 2, 3, 4};
    reverse(arr, 4);
    for (int i = 0; i < 4; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");

    int a = 5;
    int b = 10;
    swap(&a, &b);
    printf("a: %i, b: %i\n", a, b);
}

void reverse(int arr[], int len)
{
    int arr_clone[len];
    for (int i = 0; i < len; i++)
        arr_clone[i] = arr[i];

    for (int i = 0, j = (len - 1); i < len; i++, j--)
        arr[i] = arr_clone[j];
}

void swap(int* n1, int* n2)
{
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}
