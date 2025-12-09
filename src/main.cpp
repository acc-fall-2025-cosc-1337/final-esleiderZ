#include <iostream>
#include <ctime>
#include <cstdlib>
#include "die.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"
using namespace std;

int main()
{
    srand(time(0));

    Die die1;
    Die die2;
    Shooter shooter;
    Roll* roll = shooter.throw_dice(die1, die2);
    int rolled_value = roll->roll_value();

    ComeOutPhase come_out_phase;

    while (true)
    {
        RollOutcome result = come_out_phase.get_outcome(roll);

        if (result == RollOutcome::natural || result == RollOutcome::craps)
        {
            cout << "Rolled " << rolled_value << " roll again" << endl;
            roll = shooter.throw_dice(die1, die2);
            rolled_value = roll->roll_value();
        }
        else
        {
            break;
        }
    }

    cout << "Rolled " << rolled_value << " start of point phase" << endl;
    cout << "Roll until " << rolled_value << " or a 7 is rolled" << endl;

    int point = rolled_value;
    PointPhase point_phase(point);

    roll = shooter.throw_dice(die1, die2);

    while (true)
    {
        RollOutcome result = point_phase.get_outcome(roll);

        if (result == RollOutcome::point || result == RollOutcome::seven_out)
            break;

        cout << "Rolled " << roll->roll_value() << " roll again" << endl;
        roll = shooter.throw_dice(die1, die2);
    }

    cout << "Rolled " << roll->roll_value() << " end of point phase" << endl;
    shooter.display_rolled_values();
}
