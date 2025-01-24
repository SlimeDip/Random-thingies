#include <iostream>
#include <string>
#include "includes/Gachafac.cpp"
using namespace std;

// To-do
// - fix combat and boss
// - save option
// - fix ui
// - more characters

// Items
int pity = 0;
int summon = 5;
int damage = 0;
int flooor = 1;
int stage = 1;

// Characters
int Raizel_5 = 0;
int Jade_4 = 0;

// Function to clear the console screen
void clearScreen() {
    #ifdef _WIN32
        system("CLS");
    #else
        system("clear");
    #endif
}

void Gacha() {
    while (true) {
        int action;
        cout << "Choose Action:" << endl;
        cout << "Current Summons: " << summon << endl;
        cout << "Pity: " << pity << "/15" << endl;
        cout << "1. Pull" << endl;
        cout << "2. Exit" << endl;
        cout << ": ";
        cin >> action;
        //clearScreen();
        
        switch (action) {
            case 1: {
                if (summon <= 0) {
                    cout << ">> Not enough summons <<" << endl;
                    break;
                } else {
                    int random = 1 + rand() % 10;
                    summon--;
                    if (random == 3 || pity == 15) {
                        cout << ">> Damn thas krazy... 5 star <<" << endl;
                        Raizel_5++;
                        pity = 0;
                    } else {
                        cout << ">> unlucky... <<" << endl;
                        Jade_4++;
                        pity++;
                    }
                }
            }
            break;

            case 2:
                return;

            default: {
                cout << "invalid action" << endl << endl;
            }
        }
    }
}

void Explore() {
    while (true) {
        srand(time(NULL));
        int ekis = 1 + rand() % 5;
        int door;
        cout << "Current floor: " << flooor << endl;
        cout << "Pick door [1-5]" << endl;
        cout << "Return [0]" << endl;
        cout << ": ";
        cin >> door;
        //clearScreen();
        
        if (door > 5 || door <= -1) {
            cout << "!!!That door does not exist, you've fallen into the abyss!!!" << endl;
            summon--;
            return;
        }
        if (door == 0) {
            return;
        }
        
        if (door == ekis) {
            flooor = 1;
            cout << ">> Wrong door :( <<" << endl;
        } else {
            flooor++;
            cout << ">> Right door <<" << endl;
        }

        if (flooor % 5 == 0) {
            summon++;
            cout << ">> You earned +1 summon <<" << endl;
        }
    }
}

void Fight() {
    while (true) {
        srand(time(NULL));
        int Bossreward;
        int action;
        int player = (Raizel_5 * 100) + (Jade_4 * 10);
        int enemy = 15 * stage;
        
        cout << "Your Power: " << player << endl;
        if (stage % 5 == 0) {
            cout << ">> !!!Here comes the Boss Music!!! <<" << endl;
            cout << "Enemy Power: " << enemy * 2 << endl;
        } else {
            cout << "Enemy Power: " << enemy << endl;    
        }
        cout << "Choose Action [1-Fight | 2-Exit]" << endl;
        if (player < enemy) {
            cout << "You will lose, you don't have enough power yet!!!" << endl;
        }
        cout << ": ";
        cin >> action;
        //clearScreen();
        
        if (stage % 5 == 0) {
            if (action == 1) {
                if ((player - enemy) >= 0) {
                    Bossreward = 1 + rand() % 3;
                    if (Bossreward == 1) {
                        cout << ">> Boss Fight win!! << + 1 summon" << endl;
                        summon += 1;
                        stage++;
                    } else if (Bossreward == 2) {
                        cout << ">> Boss Fight win!! << + 2 summons" << endl;
                        summon += 2;
                        stage++;
                    } else if (Bossreward == 3) {
                        cout << ">> Boss Fight win!! << + 5 summons" << endl;
                        summon += 5;
                        stage++;
                    }
                } else {
                    cout << ">> Boss Fight lose <<" << endl;
                    return;
                }
            } else if (action == 2) {
                cout << "You run from the Boss Fight" << endl;
                return;
            } else {
                cout << "Invalid Action" << endl;
            }
        } else {
            if (action == 1) {
                if ((player - enemy) >= 0) {
                    cout << ">> You win!! <<" << endl;
                    stage++;
                } else {
                    cout << ">> You lose <<" << endl;
                    return;
                }
            } else if (action == 2) {
                return;
            } else {
                cout << "Invalid Action" << endl;
            }
        }
    }
}

void Characters() {
    int action;
    cout << "Raizel = " << Raizel_5 << endl;
    cout << "Jade = " << Jade_4 << endl;
    cout << "Back [0]" << endl;
    cout << ": ";
    cin >> action;
    //clearScreen();
    
    if (action == 0) {
        return;
    }
    else {
        cout << "invalid input" << endl;
    }
}

int main() {
    while (true) {
        int action;
        int move;
        if (move == 0) {
            cout << "Welcome new player, you receive 5 summons as a first timer" << endl;
        }
        cout << "Choose Action:" << endl;
        cout << "1. Explore" << endl;
        cout << "2. Fight" << endl;
        cout << "3. Gacha" << endl;
        cout << "4. Characters" << endl;
        cout << ": ";
        cin >> action;
        move++;
        clearScreen();
        
        switch (action) {
            case 1:
                Explore();
                break;
            
            case 2:
                Fight();
                break;
            
            case 3:
                Gacha();
                break;

            case 4:
                Characters();
                break;

            case 7:
                fightmenu();
                break;
            
            default:
                cout << "invalid action" << endl << endl;
        }
    }
    return 0;
}
