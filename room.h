#ifndef ROOM_H
#define ROOM_H
#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>
#include "event.h"


using namespace std;

class Room{
    private:
    Event* inRoom;
    public:
    Room();
    ~Room();

    bool is_Empty() const;
    void set_event(Event*);
    Event* get_event();
    void get_encounter();
    char get_eventType();
    void set_position(int x, int y);
    int get_positionX();
    int get_positionY();
    void print_room()const;
    bool check_eventType(char eventType);
    void get_percept();
};

#endif