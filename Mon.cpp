#include <string>
#include "Move.h"
#include "Mon.h"

using namespace std;

//default constructor with placeholder variables
Mon :: Mon()
{
    name = "Thing";
    type = "normal";
    maxHP = 100;
    moves = new Move * [3];
}

//custom constructor with input parameters
Mon :: Mon(string mName, string mType, int mMaxHP, Move ** mMoves)
{
    name = mName;
    type = mType;

    if (mMaxHP >= 0)
    {
        maxHP = mMaxHP;
    }
    else
    {
        maxHP = 0;
    }

    moves = mMoves;
}

// return name of mon
string Mon :: getName()
{
    return name;
}

// return type of mon
string Mon :: getType()
{
    return type;
}

// return max HP of mon
int Mon :: getMaxHP()
{
    return maxHP;
}

// return chosen move of mon
Move * Mon :: getMove(int index)
{
    return moves[index];
}

//delete mon
Mon :: ~Mon()
{
    delete[] moves;
}