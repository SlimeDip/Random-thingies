#include <iostream>
using namespace std;

int main() {
    double grade;
    cout << "Numerical grade: ";
    cin >> grade;
    
    if (grade > 89) {
        cout << "Your grade is A" << endl;
    }
    else if (grade > 79 && grade < 91) {
        cout << "Your grade is B" << endl;
    }
    else if (grade > 69 && grade < 81) {
        cout << "Your grade is C" << endl;
    }
    else if (grade > 59 && grade < 71) {
        cout << "Your grade is D" << endl;
    }
    else if (grade < 60) {
        cout << "Your grade is F" << endl;
    }
    else {
        cout << "Invalid input" << endl;
    }
    
    return 0;
}