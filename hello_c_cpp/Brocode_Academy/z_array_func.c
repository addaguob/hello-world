#include <stdio.h>

void print_array(int arr[], int len);
void update_array(int arr[], int len);

int main(void)
{
    int arrNums[] = {1, 4, 3};
    int len = 3;
    
    print_array(arrNums, len);
    update_array(arrNums, len);
    print_array(arrNums, len);
    
}

void print_array(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%i, ", arr[i]);

    printf("\n");
}

// modify arrays from main function demo
void update_array(int arr[], int len)
{

    // arr[] is a different array name than arrNums[]
    // but we are actually modifying arrNums[]. You will know in cs50x week 4.
    for (int i = 0; i < len; i++)
        arr[i] = i;
}