#ifndef HUMAN_H
#define HUMAN_H

#include <string>
#include "Move.h"
#include "Mon.h"
#include "Player.h"
#include "Com.h"

using namespace std;

//create human class
class Human : public Player
{
public:

    Human();
    Human(Mon * hMon, string hName);
    Human(Mon ** mons, int len);

    void intro();
    Move * chooseMove();

    ~Human();

};

#endif