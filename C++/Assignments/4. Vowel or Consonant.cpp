#include <iostream>
using namespace std;

int main() {
    char letter;
    cout << "letter: ";
    cin >> letter;
    
    if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' || letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U') {
        cout << "vowel";
    }
    else {
        cout << "consonant";
    }
    
    return 0;
}