#ifndef WUMPUS_H
#define WUMPUS_H

#include <iostream>
#include <string>
#include <vector>

#include "event.h"

using namespace std;

class Wumpus : public Event{
    protected:
    bool isAlive;
    public:
    Wumpus(); //constructor
    ~Wumpus();
    void encounter();
    bool get_isAlive();
    void print_message();
    void slain();
};

#endif