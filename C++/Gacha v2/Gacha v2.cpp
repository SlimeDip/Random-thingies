#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int const Numchar = 8;
string Character[Numchar] = {"Zeph", "Dip", "Shin", "Exks", "Mon", "Zenice", "Horhi", "Jahren"};
string Character_skill[Numchar] = {"Divine Beam", "Cursed Knowledge", "Adaptive Transformation", "Insight", "Full Send", "Berserk", "Takers of the Known", "Divine Light"};
int Character_HP[Numchar] = {25, 25, 30, 25, 15, 20, 15, 20};
int Character_AT[Numchar] = {25, 25, 20, 25, 15, 10, 15, 10};

string Character_team[3] = {"Mon", "Zenice", "Jahren"};
int Character_team_skill[3] = {4, 5, 7};
int Owned_Character[Numchar] = {0, 0, 0, 0, 1, 1, 0, 1};

void gacha();
void battle();
void adventure();
void team();
void skill(int caster, int i);
void enemy(int self);
void nextlvl();

int summon = 10;
int flooor = 1;

void clearScreen()
{
#ifdef _WIN32
    system("CLS");
#else
    system("clear");
#endif
    return;
}

int main()
{
    while (true)
    {
        string input;

        cout << "Team:" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << i + 1 << ". " << Character_team[i] << endl;
        }

        cout << endl;
        cout << "Choose input:" << endl;
        cout << "[gacha]" << endl;
        cout << "[battle]" << endl;
        cout << "[adventure]" << endl;
        cout << "[team]" << endl;
        cout << ": ";
        cin >> input;
        clearScreen();

        if (input == "gacha")
        {
            gacha();
        }
        else if (input == "battle")
        {
            battle();
        }
        else if (input == "adventure")
        {
            adventure();
        }
        else if (input == "team")
        {
            team();
        }
        else
        {
            cout << "invalid input" << endl;
        }
    }

    return 0;
}

void gacha()
{
    while (true)
    {
        int action;
        cout << "Choose Action:" << endl;
        cout << "Number of Summons: " << summon << endl;
        cout << "1. Pull" << endl;
        cout << "2. Exit" << endl;
        cout << ": ";
        cin >> action;
        clearScreen();

        switch (action)
        {
        case 1:
        {
            if (summon <= 0)
            {
                cout << ">> Not enough summons <<" << endl;
                break;
            }
            else
            {
                srand(time(NULL));
                int random = rand() % Numchar;
                summon--;

                cout << "You got " << Character[random] << endl;
                Owned_Character[random]++;
            }
        }
        break;

        case 2:
            return;

        default:
        {
            cout << "invalid action" << endl
                 << endl;
        }
        }
    }
}

void adventure()
{
    while (true)
    {
        srand(time(NULL));
        int ekis = 1 + rand() % 5;
        int door;
        cout << "Current floor: " << flooor << endl;
        cout << "Pick door [1-5]" << endl;
        cout << "Return [0]" << endl;
        cout << ": ";
        cin >> door;
        clearScreen();

        if (door > 5 || door <= -1)
        {
            cout << "!!!That door does not exist, you've fallen into the abyss!!!" << endl;
            summon--;
            return;
        }
        if (door == 0)
        {
            return;
        }

        if (door == ekis)
        {
            flooor = 1;
            cout << ">> Wrong door :( <<" << endl;
        }
        else
        {
            flooor++;
            cout << ">> Right door <<" << endl;
        }

        if (flooor % 5 == 0)
        {
            summon++;
            cout << ">> You earned +1 summon <<" << endl;
        }
    }
}

string battle_action;
int level = 1;
int skillpoints = 5;

int PlayerHP[3] = {
    Character_HP[Character_team_skill[0]] * Owned_Character[Character_team_skill[0]],
    Character_HP[Character_team_skill[1]] * Owned_Character[Character_team_skill[1]],
    Character_HP[Character_team_skill[2]] * Owned_Character[Character_team_skill[2]]};

int PlayerAT[3] = {
    Character_AT[Character_team_skill[0]] * Owned_Character[Character_team_skill[0]],
    Character_AT[Character_team_skill[1]] * Owned_Character[Character_team_skill[1]],
    Character_AT[Character_team_skill[2]] * Owned_Character[Character_team_skill[2]]};

int enemyHP[3] = {level * 20, level * 20, level * 20};
int enemyAT[3] = {level * 15, level * 15, level * 15};

void battle()
{
    while (true)
    {
        string action;
        int selection;
        bool battleOngoing = true;

        while (battleOngoing)
        {
            for (int i = 0; i < 3; i++)
            {
                if (PlayerHP[i] <= 0)
                {
                    continue;
                }

                cout << "Level: " << level << endl;
                cout << "Skillpoints: " << skillpoints << endl;

                for (int j = 0; j < 3; j++)
                {
                    cout << Character_team[j] << "\t: " << PlayerHP[j] << " HP  " << PlayerAT[j] << " ATK" << endl;
                }
                cout << endl;

                for (int j = 0; j < 3; j++)
                {
                    cout << "Enemy" << j + 1 << "\t: " << enemyHP[j] << " HP  " << enemyAT[j] << " ATK" << endl;
                }
                cout << endl;

                if (Character_HP[i] <= 0)
                {
                    continue;
                }

                int caster = Character_team_skill[i];

                cout << "What will " << Character_team[i] << " do?" << endl;
                cout << "Enter Action:" << endl;
                cout << "[attack]" << endl;
                cout << "[skill]" << endl;
                cout << "[exit]" << endl;
                cout << ": ";
                cin >> action;

                if (action == "attack")
                {
                    cout << "Choose enemy to attack: [1/2/3]" << endl;
                    cout << ": ";
                    cin >> selection;

                    if (selection >= 1 && selection <= 3)
                    {
                        clearScreen();
                        enemyHP[selection - 1] -= Character_AT[i];
                        if (enemyHP[selection - 1] < 0)
                        {
                            enemyHP[selection - 1] = 0;
                        }
                    }
                    else
                    {
                        clearScreen();
                        cout << "Invalid selection." << endl;
                    }
                }
                else if (action == "skill")
                {
                    if (skillpoints <= 0)
                    {
                        cout << "Not enough skillpoints!" << endl;
                    }
                    else
                    {
                        clearScreen();
                        skill(caster, i);
                    }
                }
                else if (action == "exit")
                {
                    clearScreen();
                    return;
                }
                else
                {
                    cout << "Invalid action." << endl;
                }

                if (enemyHP[i] > 0)
                {
                    enemy(i);
                }

                if (enemyHP[0] <= 0 && enemyHP[1] <= 0 && enemyHP[2] <= 0)
                {
                    cout << "You win!" << endl;
                    skillpoints = 5;
                    level++;
                    summon++;
                    nextlvl();
                    battleOngoing = false;
                    break;
                }

                if (Character_HP[0] <= 0 && Character_HP[1] <= 0 && Character_HP[2] <= 0)
                {
                    cout << "You lose!" << endl;
                    skillpoints = 5;
                    nextlvl();
                    battleOngoing = false;
                    break;
                }
            }
        }
    }
}

void enemy(int self)
{
    srand(time(NULL));
    int random = 1 + rand() % 5;
    int target = rand() % 3;

    switch (random)
    {
    case 1:
    {
        cout << "Enemy" << self + 1 << " attacked " << Character_team[target] << endl;
        PlayerHP[target] -= enemyAT[self];
        break;
    }
    case 2:
    {
        cout << "Enemy" << self + 1 << " healed" << endl;
        enemyHP[self] += 15 * level;
        break;
    }
    case 3:
    {
        cout << "Enemy" << self + 1 << " used debuff on " << Character_team[target] << endl;
        PlayerAT[target] *= 0.7;
        break;
    }
    case 4:
    {
        cout << "Enemy" << self + 1 << " used buff" << endl;
        enemyAT[self] *= 1.2;
        break;
    }
    case 5:
    {
        cout << "Enemy" << self + 1 << " used absorb on " << Character_team[target] << endl;
        PlayerHP[target] -= enemyAT[self] * 0.7;
        enemyHP[self] += enemyAT[self] * 1.3;
        break;
    }
    default:
        break;
    }

    return;
}

void skill(int caster, int i)
{

    switch (caster)
    {
    case 0: // Divine Beam
        cout << "You used Divine Beam!" << endl;
        cout << "-" << 1.5 * PlayerAT[i] << " on all enemy" << endl;
        for (int j = 0; j < 3; j++)
        {
            enemyHP[j] -= 1.5 * PlayerAT[i];
        }
        skillpoints -= 1;
        break;
    case 1: // Cursed Knowledge
        cout << "You used Cursed Knowledge!" << endl;
        cout << "Placed 20 percent debuff on enemy's HP and ATK" << endl;
        for (int j = 0; j < 3; j++)
        {
            enemyHP[j] *= 0.8;
            enemyAT[j] *= 0.8;
        }
        skillpoints -= 1;
        break;
    case 2: // Adaptive Transformation
        cout << "You used Adaptive Transformation!" << endl;
        cout << "Shin's HP and ATK are now swapped" << endl;
        swap(PlayerHP[i], PlayerAT[i]);
        skillpoints -= 1;
        break;
    case 3: // Insight
        cout << "You used Insight!" << endl;
        cout << "You gained 1 skillpoint" << endl;
        skillpoints += 2;
        break;
    case 4: // Full Send
        cout << "You used Full Send!" << endl;
        cout << "Team's HP and ATK is increased" << endl;
        for (int j = 0; j < 3; j++)
        {
            PlayerHP[j] *= 1.1 + (Owned_Character[4] * 0.05);
            PlayerAT[j] *= 1.1 + (Owned_Character[4] * 0.05);
        }
        skillpoints -= 1;
        break;
    case 5: // Berserk
        cout << "You used Berserk!" << endl;
        cout << "Increased ATK drastically but reduced HP" << endl;
        PlayerHP[i] *= 0.7;
        PlayerAT[i] *= 1.3;
        skillpoints -= 1;
        break;
    case 6: // Takers of the Known
        cout << "You used Takers of the Known!" << endl;
        cout << "Coppied enemy's stats" << endl;
        PlayerHP[i] = (level + Owned_Character[6] / 2) * 20;
        PlayerAT[i] = (level + Owned_Character[6] / 2) * 15;
        skillpoints -= 1;
        break;
    case 7: // Divine Light
        cout << "You used Divine Light!" << endl;
        cout << "Team was healed" << endl;
        PlayerHP[0] += Owned_Character[7] * 15;
        PlayerHP[1] += Owned_Character[7] * 15;
        PlayerHP[2] += Owned_Character[7] * 15;
        skillpoints -= 1;
        break;
    default:
        cout << "Invalid skill!" << endl;
        break;
    }
}

void team()
{
    while (true)
    {
        int selected;
        bool chosen[Numchar] = {false};
        cout << "Owned Characters:" << endl;

        for (int i = 0; i < Numchar; i++)
        {
            if (Owned_Character[i] > 0)
            {
                cout << i + 1 << ". " << Character[i] << " " << Owned_Character[i] << "x" << endl;
            }
        }

        cout << "\nChoose 3 characters for your team by number (1-" << Numchar << ")." << endl;
        cout << "Enter -1 to exit:" << endl;

        for (int i = 0; i < 3; i++)
        {
            cout << "Select character " << i + 1 << ": ";
            cin >> selected;

            if (selected == -1)
            {
                return;
            }

            if (selected > 0 && selected <= Numchar && Owned_Character[selected - 1] > 0 && !chosen[selected - 1])
            {
                Character_team[i] = Character[selected - 1];
                Character_team_skill[i] = selected - 1;
                chosen[selected - 1] = true;
            }
            else
            {
                cout << "Invalid or already chosen character. Try again." << endl;
                i--;
                continue;
            }
        }

        clearScreen();

        cout << "Your selected team:" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << i + 1 << ". " << Character_team[i] << endl;
        }

        cout << endl;
        return;
    }
}

void nextlvl()
{

    for (int i = 0; i < 3; i++)
    {
        enemyHP[i] = level * 20;
        enemyAT[i] = level * 15;

        PlayerHP[i] = Character_HP[Character_team_skill[i]] * Owned_Character[Character_team_skill[i]];
        PlayerAT[i] = Character_AT[Character_team_skill[i]] * Owned_Character[Character_team_skill[i]];
    }

    return;
}