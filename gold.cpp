#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "gold.h"

Gold::Gold():Event(){
    /*********************************************************************
    ** Function: Gold():Event()
    ** Description: constructor that initializes Gold as a child of Event
    ** Parameters: none
    ** Pre-Conditions: Gold instantiated
    ** Post-Conditions: Gold initialized
    *********************************************************************/
    this->gameMessage = "You see a glimmer out of the corner of your eye...";
    this -> eventType = 'g';
}

Gold::~Gold(){
    
}

void Gold::encounter(){
    /*********************************************************************
    ** Function: encounter()
    ** Description: outputs to console when the player enters the same square as the event
    ** Parameters: none
    ** Pre-Conditions: player enters the same square
    ** Post-Conditions: encounter output
    *********************************************************************/
    cout << "You have found the Wumpus's hoard of gold!" << endl;
    cout << "Gold obtained!" << endl;
}