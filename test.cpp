#include <iostream>
#include "classes.h"
#include "string.h"
#include "tarolo.hpp"

using namespace std;

void test()
{
    Egyesulet fitt;
    footballTeam tt62("TT62", 13, "Gorzsi", "Pityu");
    handballTeam tt72("TT72", 8, 555555);
    basketballTeam tt82 ("TT82", 9, 15);
    fitt.addTeam(tt62);
    fitt.addTeam(tt62); // nem lehet kétszer hozzáadni
    fitt.addTeam(tt72);
    fitt.addTeam(tt82);
    fitt.listAll();
    fitt.removeTeam(tt72);
    fitt.removeTeam(tt82);
    fitt.listAll();
    fitt.addTeam(tt72);
    fitt.addTeam(tt82);
    fitt.list();
    tt72.setTam(5556);
    cout << tt72.getTam() << endl;
    tt82.setPom(666);
    cout << tt62.getPom() << endl;
    return 0;
}
