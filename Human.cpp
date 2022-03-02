#include <iostream>
#include <string>
#include <stdlib.h>
#include <limits>
#include "Move.h"
#include "Mon.h"
#include "Player.h"
#include "Human.h"
#include "Com.h"

using namespace std;

// include input validation functions from input.cpp
extern int getInt(string prompt, int lower, int upper);
extern string getString(string prompt);

//create the human mon object, as well as the name and hp.
Human :: Human()
{
    mon = new Mon();
    name = mon -> getName();
    hp = mon -> getMaxHP();

    // initialise moves with 0 pp
    for (int i = 0; i < 3; i++)
    {
        pp[i] = 0;
    }
}

//inputting new variables
Human :: Human(Mon * hMon, string hName)
{
    mon = hMon;
    name = hName;
    hp = mon -> getMaxHP();

    // initialise moves with their max pp
    for (int i = 0; i < 3; i++)
    {
        pp[i] = mon -> getMove(i) -> getMaxPP();
    }
}

//asking the player to choose the mon that they want, outputting what they chose and asking the player to enter a nickname.
Human :: Human(Mon ** mons, int len)
{
    int choice;

    // display possible mons
    for (int i = 0; i < len; i++)
    {
        cout << i + 1 << " - " << mons[i] -> getName() << endl;
    }
    choice = getInt("Choose a mon: ", 1, 3); // choose using input validation function

    mon = mons[choice - 1]; // set mon to chosen from list

    // print choice and ask for input
    cout << endl << "You chose " << mon -> getName() << "!\n";
    name = getString("Enter a nickname: ");
    cout << endl;

    hp = mon -> getMaxHP();

    // initialise moves with their max pp
    for (int i = 0; i < 3; i++)
    {
        pp[i] = mon -> getMove(i) -> getMaxPP();
    }
}

// print introduction text
void Human :: intro()
{
    cout << "Player sent out " << name << "!\n\n";
}

//ask the player to choose a move and then returning the chosen move.
Move * Human :: chooseMove()
{
    int choice;

    // repeat until move is chosen
    for (;;)
    {
        cout << name << "'s Turn!" << endl;

        // if all pp is depleted, print no pp message and exit game
        if (pp[0] <= 0 && pp[1] <= 0 && pp[2] <= 0)
        {
            cout << "Oh no, there's no PP left!" << endl;
            cout << "You lose :(" << endl << endl;
            exit(0);
        }

        // print possible moves with pp and max pp
        for (int i = 0; i < 3; i++)
        {
            cout << i + 1 << " - " << mon -> getMove(i) -> getName() << " (" << pp[i] << "/" << mon -> getMove(i) -> getMaxPP() << " PP)\n";
        }
        choice = getInt("Choose a move (or 4 to exit): ", 1, 4); // choose with input validation function

        cout << endl;

        if (choice != 4) // if didn't choose exit
        {
            // return move if there's pp left
            if (pp[choice - 1] > 0)
            {
                pp[choice - 1]--;
                return mon -> getMove(choice - 1);
            }
            else // display no pp message then repeat
            {
                cout << "Move has no PP. Please choose another move.\n\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize> :: max(), '\n');
            }
        }
        else // if chose exit, exit
        {
            exit(0);
        }
    }
}

// delete the mon
Human :: ~Human()
{
    delete mon;
}