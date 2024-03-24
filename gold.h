#ifndef GOLD_H
#define GOLD_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "event.h"

class Gold : public Event{
    protected:
    public:
        Gold();
        ~Gold();
        void encounter();
};

#endif