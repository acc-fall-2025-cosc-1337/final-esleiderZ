#include "shooter.h"
#include <iostream>
using namespace std;

Roll* Shooter::throw_dice(Die& d1, Die& d2)
{
    Roll* r = new Roll(d1, d2);
    r->roll_dice();
    rolls.push_back(r);
    return r;
}

void Shooter::display_rolled_values()
{
    for (auto r : rolls)
        cout << r->roll_value() << endl;
}

Shooter::~Shooter()
{
    for (auto r : rolls)
        delete r;
}
