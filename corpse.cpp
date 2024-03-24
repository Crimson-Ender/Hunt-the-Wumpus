#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

#include "corpse.h"

using namespace std;

Corpse::Corpse():Event(){
    /*********************************************************************
    ** Function: Corpse():Event()
    ** Description: constructor that initializes Corpse as a child of Event
    ** Parameters: none
    ** Pre-Conditions: Corpse instantiated
    ** Post-Conditions: Corpse initialized
    *********************************************************************/
    this->eventType = 'c';
    this->looted = false;
    this->gameMessage = "There are blood splatters on the floor...";
}

Corpse::~Corpse(){
    
}

bool Corpse::isLooted(){
    /*********************************************************************
    ** Function: isLooted()
    ** Description: returns whether the corpse is looted or not
    ** Parameters: none
    ** Pre-Conditions: game needs to check if the corpse is looted
    ** Post-Conditions: returns looted
    *********************************************************************/
    return looted;
}

void Corpse::encounter(){
    /*********************************************************************
    ** Function: encounter()
    ** Description: outputs to console when the player enters the same square as the event
    ** Parameters: none
    ** Pre-Conditions: player enters the same square
    ** Post-Conditions: encounter output
    *********************************************************************/
    cout << "You found the body of one of the Wumpus's previous victims" << endl;
    cout << "You found 3 arrows on their body!" <<endl;
}