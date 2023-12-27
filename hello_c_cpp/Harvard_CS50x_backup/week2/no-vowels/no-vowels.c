// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>

string replace(string word);

int main(int argc, string argv[])
{
    if (argc > 1)
    {
        string word = argv[1];
        printf("%s\n", replace(word));
        return 0;
    }
    else
    {
        printf("Usage: %s word\n", argv[0]);
        return 1;
    }
}
// This function will change the following vowels to numbers:
// a becomes 6, e becomes 3, i becomes 1, o becomes 0 and u does not change.
string replace(string word)
{
    int i = 0;
    while (word[i] != '\0')
    {
        switch (word[i])
        {
            case 'a':
                word[i] = '6';
                break;
            case 'e':
                word[i] = '3';
                break;
            case 'i':
                word[i] = '1';
                break;
            case 'o':
                word[i] = '0';
                break;
        }
        i++;
    }
    return word;
}
