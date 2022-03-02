#ifndef PLAYER_H
#define PLAYER_H

#include "Move.h"
#include "Mon.h"

using namespace std;

//create the player parent class
class Player
{
protected:

    Mon * mon;
    string name;
    int hp;
    int pp[3];

public:

    Mon * getMon();
    string getName();
    bool isAlive();

    void loseHP(int dmg);
    void printHP();
    void doMove(Move * move, Player * enemy);

    virtual void intro() = 0;
    virtual Move * chooseMove() = 0;

};

#endif