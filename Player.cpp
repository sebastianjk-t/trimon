#include <iostream>
#include <string>
#include "Move.h"
#include "Mon.h"
#include "Player.h"

using namespace std;

// return player's mon
Mon * Player :: getMon()
{
    return mon;
}

// return player mon's name
string Player :: getName()
{
    return name;
}

// return true if mon is alive, false if not
bool Player :: isAlive()
{
    return hp > 0;
}

// modify hp depending on input damage
void Player :: loseHP(int dmg)
{
    hp += dmg; // dmg is negative

    if (hp < 0)
    {
        hp = 0;
    }
}

//print hp of mon as health bar
void Player :: printHP()
{
    cout << name << ": " << hp << endl;

    // print opaque if 10 hp section is 'filled' and transparent if not
    for (int i = 0; i < (mon -> getMaxHP() / 10); i++)
    {
        if (hp / 10 > i)
        {
            cout << "▓";
        }
        else
        {
            cout << "░";
        }
    }

    cout << endl;
}

//simulate move against given enemy mon
void Player :: doMove(Move * move, Player * enemy)
{
    cout << name << " used " << move -> getName() << "!\n";

    // if move is offensive
    if (move -> getDmg() < 0)
    {
        float buff = 1;

        // outer switch statement sorts by user mon's type (using first character)
        switch (mon -> getType()[0])
        {
            case 'f':
                // inner switch statements sort by enemy mon's type
                switch (enemy -> getMon() -> getType()[0])
                {
                    // if weak, set buff to half
                    case 'w':
                        buff = 0.5;
                        break;
                    // if strong, set buff to double
                    case 'g':
                        buff = 2;
                        break;
                }
                break;
            case 'w':
                switch (enemy -> getMon() -> getType()[0])
                {
                    case 'g':
                        buff = 0.5;
                        break;
                    case 'f':
                        buff = 2;
                        break;
                }
                break;
            case 'g':
                switch (enemy -> getMon() -> getType()[0])
                {
                    case 'f':
                        buff = 0.5;
                        break;
                    case 'w':
                        buff = 2;
                        break;
                }
                break;
        }

        enemy -> loseHP((int) (move -> getDmg()) * buff);
        cout << "It did " << (move -> getDmg()) * buff * -1 << " damage.";

        // print message depending on effectivenes
        switch ((int) (buff * 2)) // double and convert to int (required for switch statements)
        {
            case 4:
                cout << "..\nSuper effective!";
                break;
            case 1:
                cout << "..\nNot very effective?";
                break;
        }
    }
    else // if move is healing
    {
        hp += move -> getDmg();
        cout << "It gained " << move -> getDmg() << " HP.";

        // resets hp to max HP if gone above
        if (hp > mon -> getMaxHP())
        {
            hp = mon -> getMaxHP();
        }
    }

    cout << endl << endl;
}