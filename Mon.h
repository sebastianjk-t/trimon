#ifndef MON_H
#define MON_H

#include <string>
#include "Move.h"

using namespace std;

//create mon class
class Mon
{
private:

    string name;
    string type;
    int maxHP;
    Move ** moves;

public:

    Mon();
    Mon(string mName, string mType, int mMaxHP, Move ** mMoves);

    string getName();
    string getType();
    int getMaxHP();
    Move * getMove(int index);

    ~Mon();

};

#endif