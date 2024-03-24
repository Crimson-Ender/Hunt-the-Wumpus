#ifndef DEADGUY_H
#define DEADGUY_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

#include "event.h"

using namespace std;

/*the corpse object is an object not required within the assignment requirements. There will be
one corpse randomly placed in a room within the dungeon. The corpse is of one of the Wumpus's previous
victims. This event allows the player to loot arrows from the deceased adventurer's corpse.*/

class Corpse:public Event{
    protected:
        bool looted;
    public:
        Corpse();
        ~Corpse();
        bool isLooted();
        void encounter();
};

#endif