#include <stdio.h>

int main() {
    int MyNum = 7;
    int YourNum;
    printf("\nGuess my hidden number between 1-15!\n\n");
    do {
        printf("Enter your guess: ");
        scanf("%d", &YourNum); 
        if (YourNum == MyNum) {
            printf("Your guess is right! Congrats! ^ ^\n");
            break;
        } else if(1 <= YourNum && YourNum <= 15) {
            if(YourNum > MyNum) {
                printf("Your guess is higher than my hidden number! ^ ^\n");
            } else {
                printf("Your guess is lower than my hidden number! ^ ^\n");
            }
        } else {
            printf("Your guess is outside 1 to 15!\n");
            break;
        }
    } while (YourNum != MyNum && 1 <= YourNum && YourNum <= 15);

    printf("\n\nEnter a character to exit program. "); // Prevent closing CMD Prompt immediately
    scanf("%d", YourNum); // Alternative to getch() of conio.h
    return 0;
}
