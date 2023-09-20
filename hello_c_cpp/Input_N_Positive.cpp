#include <stdio.h>

int main() {
    int Number_ofINputs;
    int Highest_N = 0, Current_N = 0, HN_Occurence = 0;
    printf("Input a positive integer: ");
    scanf("%d", &Number_ofINputs); 
    if(Number_ofINputs > 0 && Number_ofINputs <= 20) {       // If not zero or a negative number AND NOT exceeding 20x! ^ ^    
        printf("Now, input %d numbers: ", Number_ofINputs);         //      i =  1 2 3 4 5 6 
        for(int i = 1; i <= Number_ofINputs; i++) {                 //      N =  8 4 6 8 1 8 Sample inputs
            scanf("%d", &Current_N);
            if(i ==  1) {    
                Highest_N = Current_N;
                HN_Occurence++;       
            } else { // Starting from 2nd input
                if(Current_N > Highest_N) {
                    Highest_N = Current_N;
                    HN_Occurence = 1; // Resets to 1 if there is a new highest number
                } else if(Current_N == Highest_N) {
                    HN_Occurence++; // The same highest number appears again!
                }
            }
        }
        printf("Highest number is %d.\n", Highest_N);
        // If Statement using ? and : ---> If (condition is true) ? (this is executed) : (else, this is executed) then semi-colon ';'
        (HN_Occurence > 1) ? printf("It occured %d times.", HN_Occurence) : printf("It occured %d time.", HN_Occurence);
    } else if(Number_ofINputs > 20) {
        printf("Seriously, do you really have the time to input positive numbers %dx?\n", Number_ofINputs);
    } else  {
        printf("That's a negative number! ");
    }
    printf("\n\nEnter a character to exit program. ", Number_ofINputs); // Prevent closing CMD Prompt immediately
    scanf("%d", Number_ofINputs); // Alternative to getch() of conio.h
    return 0;
}
