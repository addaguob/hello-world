#include <math.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char pjname[25];

    // printf("Enter name: ");
    // fgets(pjname, 25, stdin);

    int length = strlen(pjname);
    // P J 
    // 0 1 2
    if (length > 0)
    {
        pjname[length - 1] = '\0';
    }

    printf("Hello %s!\n", pjname);

    int age = 5;
    printf("!age = %i\n", !age);

    if (!age && age > -1)
        printf("Age = %i, Age > -1\n", !age);
    else
        printf("Age != 0, Age > -1\n");

    for (int i = 100; i > 80; i--)
        printf("%i / 2 = %i\n", i, i / 2);

    int nn = 0;

    if(!nn)
        printf("!%i\n", nn);
    else
        printf("%i\n", nn);

    return 0;
}

// For i loop
//     swapped = false
//     For j loop
//         if pairs j pairs < j + 1
//         swap pairs j and pairs j + 1
//         swapped = true
//     if nothing swapped
//         break

// //that is bubble sort, and if you insert your vairiables tracking victory strength, that will become:

// For i loop
//     swapped = false
//     For j loop
//         int victory_1 = preferences[pairs j winner][j loser] - their reverse [j loser][j winner]
//         int victory_2 = preferences j+1 same above

//         if victory_1 < victory_2 // then victory_2 comes first than v1
//         pair tmp // create pair struct as tmp
//         swap pairs tmp, j and j+1
//         swapped = true

//     if swapped false
//         break

// win_count[i] += 0; // --> not necessary because you already initialized default to 0
// win_count[j] += 0; // --> not necessary because you already initialized default to 0

// block under comment // sorted the transferred array
// sort the victory count contents but not the container (indices of pairs struct array) of those contents :(
// I also thought that win_count can contain the victory strength and that you keep track of the index of the win_count as the rank index of the pair
// but the value (not the index) will be overridden in the next iteration when the if statement is true. That is the bug, I think.