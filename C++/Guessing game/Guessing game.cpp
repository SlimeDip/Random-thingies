#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    
    int guess;
    int aguess;
    int mode;
    int i;
    
    srand(time(NULL));
    int random = rand() % 100;
    cout << "Number guesser (1-100) by F3" << endl;
    cout << "Pick modes: " << "1 (∞ tries)" << ", 2 (10 tries)" << ", 3 (5 tries)" << ", 4 (1 try)" << endl << "Mode: ";
    cin >> mode;
    
    switch (mode){
        
    case 1:
    for (i  ; aguess < i;++aguess) {
        cout << "guess: ";
        cin >> guess;
        
        if (guess > random) {
            cout << "lower" << endl;
        }
        else if (guess < random) {
            cout << "higher" << endl;
        }
        else {
            cout << endl << "You guessed it!" << endl;
            break;
        }
        
        if (random - 7 <= guess && random + 7 >= guess) {
            cout << "almost there" << endl;
        }
        
    }
    cout << "Number of guesses: " << aguess << endl;
    break;
    
    case 2: 
    for (i = 10 ;aguess < i;++aguess) {
        cout << "guess: ";
        cin >> guess;
        
        if (guess > random) {
            cout << "lower" << endl;
        }
        else if (guess < random) {
            cout << "higher" << endl;
        }
        else {
            cout << endl << "You guessed it!" << endl;
            break;
        }
       
        if (random - 7 <= guess && random + 7 >= guess) {
            cout << "almost there" << endl;
        }
        
    }
    if (aguess == 10){
            cout << endl <<  "!GAME OVER!" << endl;
    }
    cout << "Number of guesses: " << aguess << endl;
    break;
    
    case 3:
    for (i = 5 ;aguess < i;++aguess) {
        cout << "guess: ";
        cin >> guess;
        
        if (guess > random) {
            cout << "lower" << endl;
        }
        else if (guess < random) {
            cout << "higher" << endl;
        }
        else {
            cout << endl << "You guessed it!" << endl;
            break;
        }
       
        if (random - 7 <= guess && random + 7 >= guess) {
            cout << "almost there" << endl;
        }
        
    }
    if (aguess == 5){
        cout << endl << "!GAME OVER!" << endl;
    }
    cout << "Number of guesses: " << aguess << endl;
    break;
    
    case 4:
    for (i = 1 ;aguess < i;++aguess) {
        cout << "guess: ";
        cin >> guess;
        
        if (guess > random) {
            cout << "lower" << endl;
        }
        else if (guess < random) {
            cout << "higher" << endl;
        }
        else {
            cout << "you guessed it!" << endl;
            break;
        }
       
        if (random - 7 <= guess && random + 7 >= guess) {
            cout << "almost there" << endl;
        }
        
    }
    if (aguess == 1){
        cout << endl << "!GAME OVER!" << endl;
    }
    cout << "Number of guesses: " << aguess << endl;
    break;
}

    return 0;
}