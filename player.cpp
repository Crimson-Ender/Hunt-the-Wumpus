#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

#include "player.h"

using namespace std;

Player::Player(){
    /*********************************************************************
    ** Function: Player()
    ** Description: intializes the player object
    ** Parameters: none
    ** Pre-Conditions: player object instantiated
    ** Post-Conditions: player object initialized
    *********************************************************************/
    this->playerStartPos_X = 0;
    this->playerStartPos_Y = 0;
    this->playerPos_X = 0;
    this->playerPos_Y = 0;
    this->arrows = 3;
    this->dead = false;
}

Player::~Player(){

}

bool Player::isDead(){
    /*********************************************************************
    ** Function: isDead()
    ** Description: checks if the player is dead
    ** Parameters: none
    ** Pre-Conditions: game needs to check if the player is dead
    ** Post-Conditions: returns the value of the player's "dead" member
    *********************************************************************/
    return this->dead;
}

int Player::get_startX(){
    /*********************************************************************
    ** Function: get_startX()
    ** Description: returns the x-coordinate of the player's spawn point
    ** Parameters: none
    ** Pre-Conditions: 
    ** Post-Conditions: returns the x-coordinate of the player's spawn point
    *********************************************************************/
    return this->playerStartPos_X;
}

int Player::get_startY(){
    /*********************************************************************
    ** Function: get_startY()
    ** Description: returns the y-coordinate of the player's spawn point
    ** Parameters: none
    ** Pre-Conditions: 
    ** Post-Conditions: returns the y-coordinate of the player's spawn point
    *********************************************************************/
    return this->playerStartPos_Y;
}

int Player::get_currentX(){
    /*********************************************************************
    ** Function: get_scurrentX()
    ** Description: returns the x-coordinate of the player's current position
    ** Parameters: none
    ** Pre-Conditions: 
    ** Post-Conditions: returns the x-coordinate of the player's current position
    *********************************************************************/
    return this->playerPos_X;
}

int Player::get_currentY(){
    /*********************************************************************
    ** Function: get_scurrentY()
    ** Description: returns the y-coordinate of the player's current position
    ** Parameters: none
    ** Pre-Conditions: 
    ** Post-Conditions: returns the y-coordinate of the player's current position
    *********************************************************************/
    return this->playerPos_Y;
}

int Player::get_arrows(){
    /*********************************************************************
    ** Function: get_arrows()
    ** Description: gets the number of arrows the player has left
    ** Parameters: none
    ** Pre-Conditions: the game needs to check the number of arrows the player has
    ** Post-Conditions: returns the numbers of arrows the player has
    *********************************************************************/
    return this->arrows;
}

void Player::set_arrows(int num){
    /*********************************************************************
    ** Function: set_arrows()
    ** Description: adds the value passed in the argument to the player's arrow count
    ** Parameters: int num
    ** Pre-Conditions: game needs to change the number of arrows the player has
    ** Post-Conditions: player's arrow count has num added to it
    *********************************************************************/
    this->arrows = this->arrows + num;
}

void Player::set_startX(int x){
    /*********************************************************************
    ** Function: set_startX()
    ** Description: sets the player's spawn x-coordinaste to x
    ** Parameters: int x
    ** Pre-Conditions: 
    ** Post-Conditions: spawn coordinate set to x
    *********************************************************************/
    this->playerStartPos_X = x;
}

bool Player::has_arrows(){
    /*********************************************************************
    ** Function: has_arrows()
    ** Description: checks if the player has arrows
    ** Parameters: none
    ** Pre-Conditions: game needs to check the player's arrow count
    ** Post-Conditions: true returned if the player has more than 0 arrows and false if they have none
    *********************************************************************/
    if(this->arrows>0){
        return true;
    }else{
        return false;
    }
}

void Player::set_startY(int y){
    /*********************************************************************
    ** Function: set_starty()
    ** Description: sets the player's spawn y-coordinate to y
    ** Parameters: int y
    ** Pre-Conditions: 
    ** Post-Conditions: spawn coordinate set to y
    *********************************************************************/
    this->playerStartPos_Y = y;
}

void Player::set_currentX(int x){
    /*********************************************************************
    ** Function: set_currentX
    ** Description: set's the player's current x coordinate to x
    ** Parameters: int x
    ** Pre-Conditions: player needs to have their position changed
    ** Post-Conditions: player's x-position set to x
    *********************************************************************/
    this->playerPos_X = x;
}

void Player::set_currentY(int y){
    /*********************************************************************
    ** Function: set_currentY
    ** Description: set's the player's current y coordinate to y
    ** Parameters: int y
    ** Pre-Conditions: player needs to have their position changed
    ** Post-Conditions: player's y-position set to y
    *********************************************************************/
    this->playerPos_Y = y;
}

void Player::set_newPosition(int x, int y){
    /*********************************************************************
    ** Function: set_newPosition
    ** Description: changes the player's current position to x,y
    ** Parameters: int x, int y
    ** Pre-Conditions: player needs to have their position changed
    ** Post-Conditions: player's x position set to x and player's y position set to y
    *********************************************************************/
    this->playerPos_X = x;
    this->playerPos_Y = y;
}

void Player::has_died(){
    /*********************************************************************
    ** Function: has_died()
    ** Description: set's dead to true
    ** Parameters: none
    ** Pre-Conditions: player dies
    ** Post-Conditions: dead set to true
    *********************************************************************/
    this->dead = true;
}
void Player::respawn(){
    /*********************************************************************
    ** Function: respawn()
    ** Description: sets the player's X,Y coordinates back to their spawn coordinates
    ** Parameters: none
    ** Pre-Conditions: player dies and chooses to restart with the same dungeon layout
    ** Post-Conditions: player's position set to their spawn coodinates
    *********************************************************************/
    this->playerPos_X = this->playerStartPos_X;
    this->playerPos_Y = this->playerStartPos_Y;
    this->dead = false;
}