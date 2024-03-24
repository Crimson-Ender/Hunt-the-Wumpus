#include <iostream>
#include <string>
#include <vector>

#include "event.h"

using namespace std;

Event::Event(){
    /*********************************************************************
    ** Function: Event()
    ** Description: constructor for Event
    ** Parameters: none
    ** Pre-Conditions: child of Event is created
    ** Post-Conditions: child of event is initialized
    *********************************************************************/
    gameMessage = " ";
    eventType = ' ';
}

Event::~Event(){
    
}

string Event::get_gameMessage(){
    /*********************************************************************
    ** Function: get_gameMessage()
    ** Description: returns the event's gameMessage string
    ** Parameters: none
    ** Pre-Conditions: called when a player enters an adjacent square to the event
    ** Post-Conditions: message printed
    *********************************************************************/
    return this->gameMessage;
}

void Event::output_gameMessage(){
    cout << this->gameMessage;
}

int Event::get_positionX(){
    /*********************************************************************
    ** Function: get_positionX()
    ** Description: returns the event's X position
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: X position returned
    *********************************************************************/
    return this->positionX;
}
int Event::get_positionY(){
    /*********************************************************************
    ** Function: get_positionY()
    ** Description: returns the event's Y position
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: Y position returned
    *********************************************************************/
    return this->positionY;
}

void Event::set_position(int x, int y){
    /*********************************************************************
    ** Function: set_position()
    ** Description: sets an event's position to X and Y
    ** Parameters: int x, int y
    ** Pre-Conditions: none
    ** Post-Conditions: event's X and Y positions changed
    *********************************************************************/
    this->positionX = x;
    this->positionY = y;
}

char Event::get_eventType(){
    /*********************************************************************
    ** Function: get_eventType()
    ** Description: returns the event's eventType character
    ** Parameters: none
    ** Pre-Conditions: game needs to check what event is in the square
    ** Post-Conditions: eventType character returned
    *********************************************************************/
    return this->eventType;
}

void Event::display_eventType() const{
    /*********************************************************************
    ** Function: display_eventType() const
    ** Description: prints an event's eventType
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: eventType output
    *********************************************************************/
    cout << this->eventType;
}

bool Event::check_eventType(char eventType){
    /*********************************************************************
    ** Function: check_eventType()
    ** Description: checks if an events eventType is equal to the argument passed
    ** Parameters:char eventType
    ** Pre-Conditions: none
    ** Post-Conditions: returns whether the event's eventType is equal to the argument or not
    *********************************************************************/
    if(this->eventType == eventType){
        return true;
    }else{
        return false;
    }
}