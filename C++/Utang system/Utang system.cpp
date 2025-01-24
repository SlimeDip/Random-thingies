#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <limits>
using namespace std;

//sa main list
int length = 0;
vector<string> listName;
vector<int> listUtang;

//for transaction history
vector<string> HDate;
vector<int> HAmount;
vector<string> HName;
vector<char> HChange;
vector<int> HPaid;

void AddToList(string name, int amount, char change) {
    time_t timestamp;
    time(&timestamp);
    string date = ctime(&timestamp);

    length += 1;
    date.pop_back();
    HDate.push_back(date);
    HName.push_back(name);
    HAmount.push_back(amount);
    HChange.push_back(change);
    return;
}

void add() {
    string name;
    int utang;
    char change = '+';

    cin.ignore();
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter borrowed amount: ";
    cin >> utang;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input" << endl;
        return;
    }

    AddToList(name, utang, change);
    HPaid.push_back(0);
    listName.push_back(name);
    listUtang.push_back(utang);
    cout << endl;

    return;
}

void edit() {
    int number;
    string action;
    int howmuch;

    cout << "Which number to edit?: ";
    cin >> number;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input" << endl;
        return;
    }

    if (number > length) {
        cout << "That person doesnt exist" << endl;
        return;
    }

    cout << "Did " << listName[number-1] << " [pay] or [borrow]?: ";
    cin >> action;

    if (action == "pay") {
        cout << "How much did " << listName[number-1] << " pay?: ";
        cin >> howmuch;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input" << endl;
            return;
        }

        listUtang[number-1] -= howmuch;

        AddToList(listName[number-1], howmuch, '-');

        if (listUtang[number-1] <= 0) {
            cout << listName[number-1] << " paid the debt!" << endl;
            listName.erase(listName.begin() + number - 1); 
            listUtang.erase(listUtang.begin() + number - 1); 
            HPaid.push_back(1);
        } else {
            HPaid.push_back(0);
        }
        cout << endl;

    } else if (action == "borrow") {
        cout << "How much did " << listName[number-1] << " borrow?: ";
        cin >> howmuch;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input" << endl;
            return;
        }

        listUtang[number-1] += howmuch;

        AddToList(listName[number-1], howmuch, '+');
        HPaid.push_back(0);
        cout << endl;
    } else {
        cout << "invalid action" << endl;
        cout << endl;
    }
    return;
}

void history() {
    string input;

    cout << endl;
    
    for (int i = 0; i < length; i++) {
        cout << HDate[i] << " = " << HName[i] << " " << HChange[i] << HAmount[i];
        if (HPaid[i] == 1) {
            cout << " paid";
        }
        cout << endl;
    }

    cout << endl;
    
    return;
}

int main() {
    while (true) {
        string action;

        cout << ">>> UTANG SYSTEM <<<" << endl;
        if (listName.empty() == 0) {
            for (int i = 0; i < listName.size(); i++) {
                cout << i+1 << ". " << listName[i] << " - " << listUtang[i] << endl;
            }
        } else {
            cout << "-- No one in list yet --" << endl;
        }

        cout << endl << "Choose input" << endl;
        cout << "[add] = add to list" << endl;
        cout << "[edit] = edit the list" << endl;
        cout << "[history] = view transaction history" << endl;
        cout << ": ";
        cin >> action;

        if (action == "add") {
            add();
        } else if (action == "edit") {
            edit();
        } else if (action == "history") {
            history();
        } else {
            cout << "Invalid input" << endl;
        }
    }   
    return 0;
}