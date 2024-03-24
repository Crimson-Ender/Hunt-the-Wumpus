/*********************************************************************
** Program Filename: huntWumpus.cpp
** Author: Max Baker
** Date: Monday, November 21st, 2022
** Description: Hunt the Wumpus, a text/grid based C++ adventure game
** Input: user inputs for gameplay
** Output: grid-based adventure game
*********************************************************************/

#include <iostream>
#include <vector>
#include <string>

#include "game.h"

using namespace std;

int main(){
    /*********************************************************************
    ** Function: int main()
    ** Description: runs the game
    ** Parameters: none
    ** Pre-Conditions: program starts
    ** Post-Conditions: program runs, and then ends
    *********************************************************************/
    Game game;
    game.start_game();
    return 0;
}