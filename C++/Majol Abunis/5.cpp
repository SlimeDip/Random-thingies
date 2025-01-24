#include <iostream>
using namespace std;

int main()  {

  double weight, height, bmi;

  cout << "BMI calculator" << endl;
  cout << "input your weight in Kilograms: ";
  cin >> weight;
  cout << "input your height in meters: ";
  cin >> height;
  bmi = weight / (height * height);

  if (bmi < 18.5){
     cout << "underweight: " << bmi  << endl;
  }  else if (bmi < 25){
     cout << "normal weight: " << bmi  << endl;
  } else if (bmi < 30){
     cout << "overweight: " << bmi  << endl;
  } else if (bmi >= 30){
     cout << "obese: " << bmi  << endl;
  } 


    return 0;
} 