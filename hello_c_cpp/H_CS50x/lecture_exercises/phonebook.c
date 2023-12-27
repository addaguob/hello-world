#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct {
    string name;
    string phonenumber;
} Person;


int main(void)
{
    Person people[2];
    people[0].name = "Alexander";
    people[0].phonenumber = "+63 916 212 7281";
    people[1].name = "Kryzzabel";
    people[1].phonenumber = "+63 917 143 4444";
    string name = get_string("Search name: ");
    for (int i = 0; i < 2; i++)
    {
        if (strcmp(name, people[i].name) == 0)
        {
            printf("Found %s with contact number: %s.\n", people[i].name, people[i].phonenumber);
            return 0;
        }
    }

    printf("%s is not found in the phonebook.\n", name);
    return 1;
}