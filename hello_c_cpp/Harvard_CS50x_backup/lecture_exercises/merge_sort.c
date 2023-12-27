#include <cs50.h>
#include <stdio.h>

int is_unsorted(int numbers[], int len);
void merge_sort(int numbers[], int len);
void print_array(int numbers[], int len);
void sort_array(int numbers[], int len);
void swap(int *a, int *b);

int main(void)
{
    // int numbers[] = {1, 2, 3, 4, 5, 6, 7};
    // int numbers[] = {5, 2, 7, 8, 1, 9, 3, 6, 4};
    // int len = sizeof(numbers) / sizeof(numbers[0]);
    int input_num = 0;
    do
    {
        input_num = get_int("Numbers: "); // sample: 527819364
    }
    while (input_num < 0);

    int nums = input_num;
    int len = 0;
    while (nums > 0)
    {
        nums /= 10;
        len++;
    }

    int numbers[len];
    for (int i = len - 1; i >= 0; i--)
    {
        numbers[i] = (input_num % 10);
        input_num /= 10;
    }

    print_array(numbers, len);
    // O (n log n) Ω(n log n)
    merge_sort(numbers, len);
}

int is_unsorted(int numbers[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        if (numbers[i] > numbers[i + 1])
            return 1;
    }
    return 0;
}

void merge_sort(int numbers[], int len)
{
    if (len > 1)
    {
        // divide array into left and right
        int leftlen = len / 2;
        int rightlen = len - leftlen;

        int leftnum[leftlen];
        int rightnum[rightlen];
        // Divide array content into two left and right arrays
        // i = index of main array, j = index of subarray
        for (int i = 0, j = 0; i < len; i++, j++)
        {
            if (j < leftlen && i < leftlen)
                leftnum[j] = numbers[i];
            else if (i == leftlen)
                j = 0; // reset once to be used by right half
            if (i >= leftlen && j < len)
                rightnum[j] = numbers[i];
        }
        print_array(leftnum, leftlen);
        sort_array(leftnum, leftlen);
        print_array(rightnum, rightlen);
        sort_array(rightnum, rightlen);

        // Merge left (index: li) and right (index: ri) arrays
        for (int i = 0, li = 0, ri = 0; i < len; i++)
        {
            if (li < leftlen)
            {
                if (ri < rightlen)
                {
                    if (leftnum[li] < rightnum[ri])
                    {
                        numbers[i] = leftnum[li];
                        li++;
                    }
                    else
                    {
                        numbers[i] = rightnum[ri];
                        ri++;
                    }
                }
                else
                {
                    numbers[i] = leftnum[li];
                    li++;
                }
            }
            else if (ri < rightlen)
            {
                if (li < leftlen)
                {
                    if (leftnum[li] < rightnum[ri])
                    {
                        numbers[i] = leftnum[li];
                        li++;
                    }
                    else
                    {
                        numbers[i] = rightnum[ri];
                        ri++;
                    }
                }
                else
                {
                    numbers[i] = rightnum[ri];
                    ri++;
                }
            }
        }
        print_array(numbers, len);
    }
}

void print_array(int numbers[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%i ", numbers[i]);
    printf("\n");
}

void sort_array(int numbers[], int len)
{
    for (int i = 0; i < len - 1; i++)
        if (numbers[i] > numbers[i + 1])
            swap(&numbers[i], &numbers[i + 1]);

    print_array(numbers, len);

    if (is_unsorted(numbers, len))
        sort_array(numbers, len);
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
