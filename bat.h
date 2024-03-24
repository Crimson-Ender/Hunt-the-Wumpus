#ifndef BAT_H
#define BAT_H


#include <iostream>
#include <string>
#include <vector>

#include "event.h"

using namespace std;

class Bat : public Event{
    public:
        Bat(); //constructor
        ~Bat();
        void encounter();
};

#endif