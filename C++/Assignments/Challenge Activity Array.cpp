#include <iostream>
using namespace std;

int main() {
    int length;
    int number;
    int largest;
    
    cout << "Enter total number of elements (1 to 100): ";
    cin >> length;
    cout << endl;
    
    int list[length];
    
    for (int i = 0; i < length; i++) {
        cout << "Enter number " << i+1 << " : ";
        cin >> list[i];
    }
    
    largest = list[0];
    
    for (int i = 0; i < length; i++) {
        if (list[i] > largest) {
            largest = list[i];
        }
    }
    
    cout << "Largest element = " << largest;

    return 0;
}