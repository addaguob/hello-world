#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string word = get_string("Enter string: ");
    int length = strlen(word);
    printf("%i\n", length);
    int count_alphabetical = 0; // Let this be a counter of each index containing a lesser value than the next
    for (int i = 0; i < length; i++)
    {
        printf("%c ", word[i]);
        if (word[i] > word[i + 1] && i + 1 < length) // (i + 1) must not exceed length
        {
            printf("\nNot alphabetically ordered.\n");
            return 0;
        }
    }
    printf("\nAlphabetically ordered. Perfect!\n");
    // return 0; // Comment this out to check "echo $?" and confirm it really returns 0 still.
}