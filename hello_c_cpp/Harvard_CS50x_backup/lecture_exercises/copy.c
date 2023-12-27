#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");
    char *t = malloc(strlen(s) + 1);

    for (int i = 0, len = strlen(s) + 1; i < len; i++) // +1 to copy NUL
    {
        t[i] = s[i];
    }

    if (strlen(t) > 0)
        s[0] = toupper(s[0]);

    printf("%s\n", s);
    printf("%s\n", t);

    free(t);
}
