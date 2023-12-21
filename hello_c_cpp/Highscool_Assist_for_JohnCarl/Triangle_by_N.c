#include <stdio.h>
#include <conio.h>

int main() {
    int UserNumber;
    printf("Enter a number: ");
    scanf("%d", &UserNumber);
    for(int Counter = 1; Counter <= UserNumber; Counter++) {
        for(int Asterisk = Counter; Asterisk > 0; Asterisk--) {
            printf("*"); // print '*' according to current value of Counter
        }
        printf("\n"); //line break
    }
    return 0;
}
