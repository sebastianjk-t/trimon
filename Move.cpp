#include <string>
#include "Move.h"

using namespace std;

//default constructor with placeholder variables
Move :: Move()
{
    name = "Nothing";
    dmg = 0;
    maxPP = 0;
}

//custom constructor with input parameters
Move :: Move(string mName, int mDmg, int mMaxPP)
{
    name = mName;
    dmg = mDmg;

    if (mMaxPP >= 0)
    {
        maxPP = mMaxPP;
    }
    else
    {
        maxPP = 0;
    }
}

// return name of move
string Move :: getName()
{
    return name;
}

// return damage of move
int Move :: getDmg()
{
    return dmg;
}

// return max PP of move
int Move :: getMaxPP()
{
    return maxPP;
}

// destructor
Move :: ~Move()
{
}