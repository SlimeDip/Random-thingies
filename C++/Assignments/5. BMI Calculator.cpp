#include <iostream>
using namespace std;

int main() {
    double weight;
    double height; 
    double BMI;
    
    cout << "weight [kg]: ";
    cin >> weight;
    cout << "height [m]: ";
    cin >> height;
    
    BMI = (weight)/(height*height);
    
    if (BMI < 18.5) {
        cout << "You are underweight";
    }
    else if (BMI < 25 && BMI >= 18.5) {
        cout << "Normal weight";
    }
    else if (BMI < 30 && BMI >= 25) {
        cout << "You are overweight";
    }
    else {
        cout << "You are obese";
    }
    
    return 0;
}