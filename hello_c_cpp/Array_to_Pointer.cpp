#include <iostream>
using namespace std;

int main() {
    char aChars[] = {'a', 'b', 'c', 'd', '\0'};
    char* pChar = aChars;
    while (*pChar++)
        cout << *pChar;
    delete pChar;
}
