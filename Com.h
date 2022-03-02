#ifndef COM_H
#define COM_H

#include <string>
#include "Move.h"
#include "Mon.h"
#include "Player.h"
#include "Human.h"

using namespace std;

//create computer class
class Com : public Player
{
private:

    string nature;

public:

    Com();
    Com(Mon * cMon, string cNature);
    Com(Mon ** mons, int len);

    void intro();
    Move * chooseMove();

    ~Com();

};

#endif