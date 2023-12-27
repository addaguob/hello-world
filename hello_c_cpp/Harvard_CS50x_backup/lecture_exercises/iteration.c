#include <cs50.h>
#include <stdio.h>

void draw(int height);

int main()
{
    int height = get_int("Enter height: ");
    draw(height);
    return 0;
}

void draw(int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
