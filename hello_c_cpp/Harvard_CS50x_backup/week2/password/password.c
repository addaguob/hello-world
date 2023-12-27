// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int i = 0;
    bool has_uppercase = false;
    bool has_lowercase = false;
    bool has_numeric = false;
    bool has_symbol = false;
    while (password[i] != '\0')
    {
        if (isupper(password[i]))
            has_uppercase = true;
        if (islower(password[i]))
            has_lowercase = true;
        if (isdigit(password[i]))
            has_numeric = true;
        if (ispunct(password[i]))
            has_symbol = true;
        i++;
    }

    if (has_uppercase == has_lowercase == has_numeric == has_symbol == true)
    {
        return true;
    }
    return false;
}
