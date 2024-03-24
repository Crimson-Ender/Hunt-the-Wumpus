#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Event{
    protected:
        int positionX; 
        int positionY;
        string gameMessage;
        char eventType;
    public:
        Event();
        virtual string get_gameMessage();
        virtual void output_gameMessage();
        virtual int get_positionX();
        virtual int get_positionY();
        virtual void set_position(int x, int y);
        virtual void encounter() = 0;
        virtual char get_eventType();
        virtual void display_eventType() const;
        virtual bool check_eventType(char eventType);
        virtual ~Event();

};

#endif