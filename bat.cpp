#include <iostream>
#include <string>
#include <vector>

#include "bat.h"

using namespace std;

Bat::Bat():Event(){
    /*********************************************************************
    ** Function: Bat():Event()
    ** Description: constructor that initializes bat as a child of Event
    ** Parameters: none
    ** Pre-Conditions: bat instantiated
    ** Post-Conditions: bat initialized
    *********************************************************************/
    this->gameMessage = "You hear squeaking and large wings flapping nearby.";
    this->eventType = 'b';
}

Bat::~Bat(){
    
}

void Bat::encounter(){
    /*********************************************************************
    ** Function: encounter()
    ** Description: outputs to console when the player enters the same square as the event
    ** Parameters: none
    ** Pre-Conditions: player enters the same square
    ** Post-Conditions: encounter output
    *********************************************************************/
    cout << "You have been ambushed by giant bats!" << endl;
    cout << "They have carried you off to another room!" <<endl;
}