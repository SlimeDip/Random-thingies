#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

int blackjack() {
    int hand = 0, dealer = 0;
    
    while (true) {
        srand(time(NULL));
        string action;

        cout << "action [hit] [stay]: ";
        cin >> action;
        
        if (action == "hit") {
            int random = 1 + rand() % 13;
        
            if (random <= 10) {
            cout << "+ " << random << endl;
            hand += random;
            cout << "card value: " << hand << endl << endl;
            } 
            if (random == 11) {
                cout << "+ " << "JACK" << endl;
                hand += random - 1;
                cout << "card value: " << hand << endl << endl;
            }
            if (random == 12) {
                 cout << "+ " << "QUEEN" << endl;
                hand += random - 2;
                cout << "card value: " << hand << endl << endl;
            }
            if (random == 13) {
                 cout << "+ " << "KING" << endl;
                hand += random - 3;
                cout << "card value: " << hand << endl << endl;
            }
                
            if (hand == 21) {
                cout << "YOU WON!" << endl << endl;
                return 2;
                break;
            }
            else if (hand > 21) {
                cout << "YOU LOSE!" << endl << endl;
                return 1;
                break;
            }
        }
            
        else if (action == "stay") {
            while (dealer < 17) {
                int dealer_random = 1 + rand() % 13;
                usleep(1000000);
                
                if (dealer_random <= 10) {
                    cout << "dealer " <<  "+ " << dealer_random << endl;
                    dealer += dealer_random;
                    cout << "dealer card value: " << dealer << endl << endl;
                }
                else if (dealer_random == 11) {
                    cout << "dealer " << "+ " << "JACK" << endl;
                    dealer += dealer_random - 1;
                    cout << "dealer card value: " << dealer << endl << endl;
                }
                else if (dealer_random == 12) {
                    cout << "dealer " <<  "+ " << "QUEEN" << endl;
                    dealer += dealer_random - 2;
                    cout << "dealer card value: " << dealer << endl << endl;
                }
                else if (dealer_random == 13) {
                    cout << "dealer " <<  "+ " << "KING" << endl;
                    dealer += dealer_random - 3;
                    cout << "dealer card value: " << dealer << endl << endl;
                }
            }
            
            if (dealer == 21) {
                cout << "THE DEALER WON, YOU LOSE!" << endl << endl;
                return 1;
                break;
            }
            if (dealer > 21) {
                cout << "DEALER BUST, YOU WON!" << endl << endl;
                return 2;
                break;
            }
            if (hand > dealer) {
                cout << "YOU WON!" << endl << endl;
                return 2;
                break;
            }
            if (dealer > hand) {
                cout << "YOU LOSE!" << endl << endl;
                return 1;
                break;
            }
            if (dealer == hand) {
                cout << "Draw" << endl << endl;
                return 3;
                break;
            }    
        }
    }
    return 0;
}

int main() {
    cout << "F3 shitty blackjack" << endl << endl;
    int money = 500, bet;
    
    while (true) {
        cout << "How much you want to bet?" << endl << "current money: " << money << endl << "bet: ";
        cin >> bet;

        if (bet > money) {
            cout << "not enough money" << endl;
        }
        else if (bet <= -1) {
            cout << "negative number is not allowed" << endl;
        }
        else if (bet == 0) {
            break;
        }
        else {
            money -= bet;
            cout << "- " << bet << endl << endl;

            int condition = blackjack();
            
            if (condition == 2) {
            money += bet * 2;
            }
            else if (condition == 3) {
                money += bet;
            }
        }
    }
    return 0;
}