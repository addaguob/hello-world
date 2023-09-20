#include <iostream>
using namespace std;

int main() {
    int UserNumber;
    cout << "Enter a number: ";
    cin >> UserNumber;
    for(int Counter = 1; Counter <= UserNumber; Counter++) {
        for(int Asterisk = Counter; Asterisk > 0; Asterisk--) {
            cout << '*'; // print '*' according to current value of Counter
        }
        cout << endl; //line break
    }
    return 0;
}
