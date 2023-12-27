#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    for (int i = 0; i < argc; i++)
    {
        printf("argv[%i] is %s\n", i, argv[i]);
    }

    printf("Hello, ");
    for (int i = 1; i < argc; i++)
    {
        printf("%c", argv[i][0]);
    }
    printf("!\n");
}