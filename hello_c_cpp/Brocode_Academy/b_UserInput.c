#include <stdio.h>
#include <string.h>

int main()
{
    // User input
    char input_name[25]; //bytes
    int input_age;

    printf("\nWhat's your name? ");
    // scanf("%s", &input_name); // this can't capture whitespace
    fgets(input_name, sizeof(input_name), stdin); // this will capture \r newline though so
    int length = strlen(input_name);
    printf("Length: %i\n", length);
    input_name[strlen(input_name) - 1] = '\0';

    printf("How old are you? ");
    scanf("%i", &input_age);

    printf("\nHello %s, how are you? ", input_name);
    printf("\nYou are %i years old.\n", input_age);

    if (input_age == 0)
        printf("Zero age, really?\n");
    else if (input_age < 5)
        printf("Less than five!\n");
    else if (input_age > 5)
        printf("Above five!\n");

    return 0;
}