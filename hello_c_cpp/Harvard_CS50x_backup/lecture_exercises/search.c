#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main()
{
    string my_residence[] = {"Dwight", "Emily", "Demil", "Angel", "Kryzza", "Alexander"};
    string search_name = get_string("Search who? Name: ");

    for(int i = 0; i < 6; i++)
    {
        if (strcmp(search_name, my_residence[i]) == 0)
        {
            printf("Found %s in %i index.\n", search_name, i);
            return 0;
        }
    }
    printf("%s is not in the list.\n", search_name);
    return 1;

}