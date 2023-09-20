#include <stdio.h>

int main() {
    int Num;
    int Sum = 0;
    printf("\nInput negative number to exit this program.\n\n");
    do {
        printf("Input a positive integer: ");
        scanf("%d", &Num); 
        if (Num >= 0) Sum = Sum + Num; // Not to add negative number
    } while (Num >= 0);
    printf("You entered a negative number!\n");
    printf("The sum of positive integers you entered is %d.\n", Sum);
    printf("\n\nEnter a character to exit program. ", Num); // Prevent closing CMD Prompt immediately
    scanf("%d", Num); // Alternative to getch() of conio.h
    return 0;
}
