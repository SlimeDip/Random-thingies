#include <iostream>
using namespace std;

int main() {
    double num;
    cout << "number: ";
    cin >> num;
    
    if (num % 2 == 0) {
        cout << "even";
    }
    else if (num == 0) {
        cout << "zero";
    }
    else {
        cout << "odd";
    }
    
    return 0;
}