#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include "pit.h"

using namespace std;

Pit::Pit():Event(){
    /*********************************************************************
    ** Function: Pit():Event()
    ** Description: constructor that initializes Pit as a child of Event
    ** Parameters: none
    ** Pre-Conditions: Pit instantiated
    ** Post-Conditions: Pit initialized
    *********************************************************************/
    this->gameMessage = "You feel a breeze...";
    this->eventType = 'p';
}

Pit::~Pit(){
    
}

void Pit::encounter(){
    /*********************************************************************
    ** Function: encounter()
    ** Description: outputs to console when the player enters the same square as the event
    ** Parameters: none
    ** Pre-Conditions: player enters the same square
    ** Post-Conditions: encounter output
    *********************************************************************/
    cout << "You've fallen down a deep pit in the ground!" << endl;
    cout << endl;
    cout << "YOU DIED!" << endl;
}