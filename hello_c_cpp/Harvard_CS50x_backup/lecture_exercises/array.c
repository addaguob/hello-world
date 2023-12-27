#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int length = 0;
    do
    {
        length = get_int("Array length: ");
    }
    while (length < 1 || length > 100);

    int iArray[length];
    
    for (int i = 0; i < length; i++)
    {
        if (i == 0)
        {
            iArray[i] = 1;
        }
        else
        {
            iArray[i] = iArray[i - 1] * 2;
        }
        printf("%i\n", iArray[i]);
    }
}
