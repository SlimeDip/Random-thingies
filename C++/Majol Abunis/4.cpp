#include <iostream>
using namespace std;

int main()  {
  
  char letter;
  
  cout << "Input a letter: ";
  cin >> letter;
  
  if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' || letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U'){
     cout << "vowel" << endl;
  } else {
      cout << "consonant" << endl;
  }
  
  
    return 0;
}