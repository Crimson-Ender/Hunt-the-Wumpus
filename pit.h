#ifndef PIT_H
#define PIT_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include "event.h"

using namespace std;

class Pit: public Event{
    public:
        Pit();
        ~Pit();
        void encounter();
};

#endif