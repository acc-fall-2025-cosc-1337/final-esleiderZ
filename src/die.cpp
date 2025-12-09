#include <cstdlib>
#include <ctime>
#include "die.h"

int Die::roll()
{
    static bool seeded = false;
    if (!seeded)
    {
        std::srand(std::time(nullptr));
        seeded = true;
    }
    return std::rand() % sides + 1;
}
