#include <iostream>
using namespace std;

int main()  {

  int num;

  cout << "Input a number: ";
  cin >> num;

  if (num > 0){
     cout << "Positive" << endl;
  } else if (num < 0) {
     cout << "negative" << endl; 
  } else {
      cout << "zero" << endl;
  }


    return 0;
}