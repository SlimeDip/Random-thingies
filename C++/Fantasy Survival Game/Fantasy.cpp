#include <iostream>
using namespace std;

/*UPDATE LOG
- fixed enemy
*/

/*FEATURES TO ADD
- resting increases chance of getting ambushed
- potions
- hunger and fatigue
- shop
*/

// Variables for main game
int day = 1;
int life = 100;
int knowledge = 5;
int gold = 0;
int mana = 10;
int strength = 10;
int ambush = 0;

//enemy
int enemy = 100;
int enemyATK = 25;

void Enemy() {
    srand(time(NULL));
    int random = 1 + rand() % 3;
    
    if (random == 1) {
        cout << ">> Enemy Attacked <<" << endl;
        life -= 15+(day);
    }
    else if (random == 2) {
        cout << ">> Enemy Healed <<" << endl;
        enemy += 15+(day/4);
    }
    else {
        cout << ">> Enemy Boosts <<" << endl;
        enemyATK += 5+(day/4);
    }
}

void Player(int action) {
    if (action == 1) {
        cout << ">> Player Attacked <<" << endl;
        enemy -= strength;
    }
    else if (action == 2) {
        if (mana >= 2) {
            cout << ">> Player used Magic <<" << endl;
            enemy -= strength*1.5;
            mana -= 2;
        }
        else {
            cout << "not enough mana" << endl;
        }
    }
    else if (action == 3) {
        cout << ">> Player Healed <<" << endl;
        life += 15;
        mana -= 2;
    }
    else {
        cout << "invalid input" << endl;
    }
}

void battle() { 
    while (true) {
        int action;
        cout << "player: " << life << "HP" << endl;
        cout << "enemy: " << enemy << "HP" << endl;
        cout << endl << "Action [1 Fight|2 Magic|3 Heal]: ";
        cin >> action;
        
        Player(action);
        Enemy();

        if (enemy <= 0) {
            cout << "You win!" << endl;
            gold += 10;
            enemy += 100+(day*1.3);
            return;
        }
        else if (life <= 0) {
            return;
        }
    }
}

void randomevents() {
    srand(time(NULL));
    int random = 1 + rand() % 5;

    if (day % 3 == 0 && strength <= 20 && mana && 20) {
        cout << "Oh no! You got robbed" << endl;
        cout << "-10g" << endl;
        gold -= 10;
    }

    if (random == 1) {
        battle();
    }
    else if (random == 2) {
        cout << "+1 Mana restored" << endl;
        mana += 1;
    }
   
}

int main() {
    while (true) {
        int action;
        cout << "Day - " << day << endl;
        cout << "Health - " << life << "HP" << endl;
        cout << "Gold - " << gold << "g" << endl;
        cout << "MN: " << mana << "  " << "STR: " << strength << endl;
        cout << endl;
        cout << "1 - battle" << endl;
        cout << "2 - train" << endl;
        cout << "3 - work" << endl;
        cout << "4 - rest" << endl;
        cout << "5 - others" << endl;
        cout << ": ";
        cin >> action;

        switch (action)
        {
        case 1:
            //battle();
            break;
        case 2:
            life -= 10;
            strength += 1;
            day += 1;
            break;
        case 3:
            life -= 5;
            gold +=15;
            day += 1;
            break;
        case 4:
            life += 10;
            day += 1;
            ambush += 1;
            break;
        case 5:
            //others();
        default:
            break;
        }

        randomevents();
        if (life <= 0) {
            cout << "You lost!" << endl;
            return 0;
        }
    }
    return 0;
}