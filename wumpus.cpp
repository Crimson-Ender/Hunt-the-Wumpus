#include <iostream>
#include <string>
#include <vector>

#include "event.h"
#include "wumpus.h"

using namespace std;

Wumpus::Wumpus():Event(){
    /*********************************************************************
    ** Function: Wumpus():Event()
    ** Description: constructor that initializes Wumpus as a child of Event
    ** Parameters: none
    ** Pre-Conditions: Wumpus instantiated
    ** Post-Conditions: Wumpus initialized
    *********************************************************************/
    this->gameMessage = "A horrific stench assaults your nostrils...";
    this->isAlive = true;
    this->eventType = 'w';
}

Wumpus::~Wumpus(){
    
}

bool Wumpus::get_isAlive(){
    /*********************************************************************
    ** Function: get_isAlive()
    ** Description: checks if the wumpus is alive
    ** Parameters: none
    ** Pre-Conditions: the game needs to check if the wumpus is dead or alive
    ** Post-Conditions: return isAlive
    *********************************************************************/
    return isAlive;
}

void Wumpus::slain(){
    this->isAlive = false;
}

void Wumpus::encounter(){
    /*********************************************************************
    ** Function: encounter()
    ** Description: outputs to console when the player enters the same square as the event
    ** Parameters: none
    ** Pre-Conditions: player enters the same square
    ** Post-Conditions: encounter output
    *********************************************************************/
    cout << "You've awoken the Wumpus!" << endl;
    cout << "Angry after being awoken from its peaceful slumber, the Wumpus eats you." << endl;
    cout <<endl;
    cout << "YOU DIED!" << endl;
}