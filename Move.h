#ifndef MOVE_H
#define MOVE_H

#include <string>

using namespace std;

//create move class
class Move
{
private:

    string name;
    int dmg;
    int maxPP;

public:

    Move();
    Move(string mName, int mDmg, int mMaxPP);

    string getName();
    int getDmg();
    int getMaxPP();

    ~Move();

};

#endif