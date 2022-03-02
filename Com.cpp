#include <iostream>
#include <string>
#include "Move.h"
#include "Mon.h"
#include "Player.h"
#include "Com.h"
#include "Human.h"

using namespace std;

//create a mon object, as well as assigning the object a name, hp and nature
Com :: Com()
{
    mon = new Mon();
    name = mon -> getName();
    hp = mon -> getMaxHP();
    nature = "neutral";

    // initialise moves with 0 pp
    for (int i = 0; i < 3; i++)
    {
        pp[i] = 0;
    }
}

//inputting new variables
Com :: Com(Mon * cMon, string cNature)
{
    mon = cMon;
    name = mon -> getName();
    hp = mon -> getMaxHP();
    nature = cNature;

    // initialise moves with their max pp
    for (int i = 0; i < 3; i++)
    {
        pp[i] = mon -> getMove(i) -> getMaxPP();
    }
}

Com :: Com(Mon ** mons, int len)
{
    srand((unsigned int) time(NULL) * rand()); // reset rng

    mon = mons[rand() % len];
    name = mon -> getName();
    hp = mon -> getMaxHP();

    // initialise moves with their max pp
    for (int i = 0; i < 3; i++)
    {
        pp[i] = mon -> getMove(i) -> getMaxPP();
    }

    //use switch statement to randomly decide between 3 different nature types.
    switch (rand() % 3)
    {
        case 0:
            nature = "neutral";
            break;
        case 1:
            nature = "hostile";
            break;
        case 2:
            nature = "passive";
            break;
    }
}

// print introduction text
void Com :: intro()
{
    cout << "A " << nature << " " << name << " appeared!\n\n";
}

//use switch statement to randomise the move that the computer player will do.
Move * Com :: chooseMove()
{
    // reset rng
    srand((unsigned int) time(NULL) * rand());

    int choice;

    // repeat until move is chosen
    for (;;)
    {
        // chooses depending on nature, sorting by first character
        switch (nature[0])
        {
            case 'h': // if hostile, choose first (strongest) move if available, else change to neutral and repeat

                if (pp[0] <= 0)
                {
                    nature = "neutral"; // change if hostile not possible
                    break;
                }

                pp[0]--;
                return mon -> getMove(0);

            case 'p': // if passive, choose second (weak) or third (heal) move if available, else change to neutral and repeat

                choice = rand() % 2 + 1;

                if (pp[choice] <= 0)
                {
                    choice = !(choice - 1) + 1; // 1 -> 2 and 2 -> 1

                    if (pp[choice] <= 0)
                    {
                        nature = "neutral";
                        break;
                    }
                }

                pp[choice]--;
                return mon -> getMove(choice);

            default: // if neutral choose random of three moves if available, else print run out of moves message and exit program

                choice = rand() % 3;

                for (int i = 0; i < 3; i++)
                {
                    if (pp[choice] > 0)
                    {
                        pp[choice]--;
                        return mon -> getMove(choice);
                    }

                    choice = (choice + 1) % 3;
                }

                cout << "Enemy has run out of moves!\nYou win :)\n";
                exit(0);
        }
    }
}

//delete the mon
Com :: ~Com()
{
    delete mon;
}