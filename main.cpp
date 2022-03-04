#include <iostream>
#include <string>
#include "Move.h"
#include "Mon.h"
#include "Player.h"
#include "Human.h"
#include "Com.h"

using namespace std;

// include input validation functions from input.cpp
extern int getInt(string prompt, int lower, int upper);

// simulate battle between two given mons, ending when either reaches 0 hp
void battle(Player * p1, Player * p2)
{
    //use while loop to continue the batlle until a mon health reaches 0.
    while (p1 -> isAlive() && p2 -> isAlive())
    {
        p1 -> printHP();
        p2 -> printHP();
        cout << endl;

        p1 -> doMove(p1 -> chooseMove(), p2);

        // run second player's turn if they haven't fainted
        if (p2 -> isAlive())
        {
            p1 -> printHP();
            p2 -> printHP();
            cout << endl;

            p2 -> doMove(p2 -> chooseMove(), p1);
        }
    }

    p1 -> printHP();
    p2 -> printHP();
    cout << endl;
}

// randomly choose computer mon from array, prompt player to choose theirs, and run battle
void encounter(Mon ** mons, int len)
{
    Player * p2 = new Com(mons, len);
    p2 -> intro();

    Player * p1 = new Human(mons, len);
    p1 -> intro();

    battle(p1, p2);

    //use an if else statement to output if the player wins or loses based on if their health runs out before the computer mon does.
    if (p1 -> isAlive())
    {
        cout << p2 -> getName() << " fainted!" << endl;
        cout << "You win :)" << endl;
    }
    else
    {
        cout << p1 -> getName() << " fainted..." << endl;
        cout << "You lose :(" << endl;
    }
}

// randomly choose two computer mons from array and simulate battle
void simulate(Mon ** mons, int len)
{
    Player * p1 = new Com(mons, len);
    Player * p2 = new Com(mons, len);

    p1 -> intro();
    p2 -> intro();

    battle(p1, p2);

    //use an if else statement to output which mon wins based on whose health runs out first
    if (p1 -> isAlive())
    {
        cout << p2 -> getName() << " fainted!" << endl;
        cout << p1 -> getName() << " wins!" << endl;
    }
    else
    {
        cout << p1 -> getName() << " fainted!" << endl;
        cout << p2 -> getName() << " wins!" << endl;
    }
}

// prompt players to choose mon from array, then run battle
void multi(Mon ** mons, int len)
{
    cout << "Player 1's Turn!\n";
    Player * p1 = new Human(mons, len);

    cout << "Player 2's Turn!\n";
    Player * p2 = new Human(mons, len);

    cout << "Player 1 sent out " << p1 -> getName() << "!\n\n";
    cout << "Player 2 sent out " << p2 -> getName() << "!\n\n";

    battle(p1, p2);

    //use an if else statement to output if player 1 or 2 wins based on whose health runs out first
    if (p1 -> isAlive())
    {
        cout << p2 -> getName() << " fainted!" << endl;
        cout << "Player 1 wins!" << endl;
    }
    else
    {
        cout << p1 -> getName() << " fainted!" << endl;
        cout << "Player 2 wins!" << endl;
    }
}

int main()
{
    // create moves
    Move ** mainMoves = new Move * [3];
    mainMoves[0] = new Move("Blast", -40, 3);
    mainMoves[1] = new Move("Bite", -20, 9);
    mainMoves[2] = new Move("Heal", 30, 6);

    // create mons
    Mon ** mainMons = new Mon * [3];
    mainMons[0] = new Mon("Fire Dino", "fire", 200, mainMoves);
    mainMons[1] = new Mon("Water Turtle", "water", 200, mainMoves);
    mainMons[2] = new Mon("Grass Dog", "grass", 200, mainMoves);
	
	cout << endl;

    int choice;

    choice = getInt("Choose a Gamemode (1 - Singleplayer, 2 - Multiplayer, 3 - Simulation): ", 1, 3);
    cout << endl;

    // run function depending on choice
    switch (choice)
    {
        case 1:
            encounter(mainMons, 3);
            break;
        case 2:
            multi(mainMons, 3);
            break;
        case 3:
            simulate(mainMons, 3);
            break;
    }

    cout << endl;

    // delete objects created in main
    delete[] mainMoves;
    delete[] mainMons;

    return 0;
}
