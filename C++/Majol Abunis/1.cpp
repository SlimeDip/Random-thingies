#include <iostream>
using namespace std;

int main()  {

  int grade;

  cout << "Input your numerical grade: ";
  cin >> grade;

  if (100 >= grade && grade >= 90){
    cout << "A" << endl;
  } else if (89 >= grade && grade >= 80){
    cout << "B" << endl;
  } else if (79 >= grade && grade >= 70){
    cout << "C" << endl;
  } else if (69 >=  grade && grade >= 65){
    cout << "D" << endl;
  } else if (grade <= 64){
    cout << "F" << endl;
  } else {
      cout << "wrong input!!!" << endl;
  }

    return 0;
}