#include <cs50.h>
#include <stdio.h>
#include <string.h>


typedef struct
{
    string name;
    string number;
} person;

int main()
{
    person people[2];
    people[0].name = "Kryzza";
    people[0].number = "0915143";
    people[1].name = "Alex";
    people[1].number = "0916212";

    string name = get_string("Search name: ");
    for (int i = 0; i < 2; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found %s with number %s.\n", people[i].name, people[i].number);
            return 0;
        }
    }
    printf("Not found.\n");
    return 1;
}