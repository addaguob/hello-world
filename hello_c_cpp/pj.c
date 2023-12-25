#include <stdio.h>
#include <string.h>

int main()
{
    char pjname[25];

    printf("Enter name: ");
    fgets(pjname, 25, stdin);

    int length = strlen(pjname);
    // P J 
    // 0 1 2
    pjname[length - 1] = '\0';


    printf("Hello %s, how are your? Your", pjname);

    return 0;
}