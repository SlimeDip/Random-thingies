#include <iostream>
using namespace std;

int main()  {

  int num;

  cout << "Input a number: ";
  cin >> num;

  if (num % 2 == 0){
     cout << "Even" << endl;
  } else {
     cout << "Odd" << endl; 
  }

    return 0;
}