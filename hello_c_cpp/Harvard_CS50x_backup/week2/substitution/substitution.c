/*
Design and implement a program, substitution,
that encrypts messages using a substitution cipher.
*/
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int invalid(string key);
void print_ciphertext_of(string plaintext, string key);

int main(int argc, string argv[])
{
    // run program with one arugment which is KEY
    // sample keys YTNSHKVEFXRBAUQZCLWDMIPGJO, VCHPRZGJNTLSKFBDQWAXEUYMOI
    int argument = argc;
    string key = argv[1];

    if (argument == 1 || argument > 2) // accept only one argument
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (invalid(key))
    {
        printf("Key must contain 26 letters with each letter being unique.\n");
        return 1;
    }
    else
    {
        // proper program begins here
        string plaintext = get_string("plaintext: ");
        print_ciphertext_of(plaintext, key);
    }
    return 0;
}

int invalid(string key)
{
    int len = strlen(key);

    if (len != 26) // valid key has 26 letters
        return 1;
    else
    {
        for (int i = 0; i < len; i++)
        {
            if (isalpha(key[i]))
            {
                for (int j = i + 1; j < len; j++)
                    if (tolower(key[i]) == tolower(key[j]))
                        return 1;
            }
            else
                return 1;
        }
        return 0; // if all bytes are letters
    }
}

void print_ciphertext_of(string plaintext, string key)
{
    int len = strlen(plaintext);
    int key_len = strlen(key);
    string letters = "abcdefghijklmnopqrstuvwxyz";
    string ciphertext = plaintext; // preserve non-alpha characters

    for (int i = 0; i < len; i++)
    {
        if (isalpha(plaintext[i]))
        {
            for (int j = 0; j < key_len; j++)
            {
                // character could be in lowercase already:
                if (plaintext[i] == letters[j])
                {
                    ciphertext[i] = tolower(key[j]);
                    break; // to return to outer loop
                }
                // or if it's in uppercase then:
                else if (plaintext[i] == toupper(letters[j]))
                {
                    ciphertext[i] = toupper(key[j]);
                    break; // to return to outer loop

                } // else, if it's a different letter, let's move on.
            }
        } // maybe it's a punctuation, number or a special character
        else
            continue;
    }
    printf("ciphertext: %s\n", ciphertext);
}
