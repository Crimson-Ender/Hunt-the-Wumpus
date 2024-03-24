#include <iostream>
#include <string>
#include <vector>
#include "game.h"

using namespace std;

void Game::get_input(){
    getline(cin, control);
}

// void Game::control_player(){
// /*********************************************************************
// ** Function: control_player()
// ** Description: takes player input and moves the player accordingly
// ** Parameters: none
// ** Pre-Conditions: user input, WASD
// ** Post-Conditions: player object is moved to an adjacent room where in the direction the user input
// *********************************************************************/
//     if(this->control == 'w' && player_inBounds(player.get_currentX()-1, player.get_currentY())){
//         //move the player up
//         move_up();
//     }else if(this->control = 'a' && player_inBounds(player.get_currentX(),player.get_currentY()-1)){
//         //move the player to the left
//         move_left();
//     }else if(this->control = 'd' && player_inBounds(player.get_currentX(),player.get_currentY()+1)){
//         //move the player to the right
//         move_right();
//     }else if (this->control == 's' && player_inBounds(player.get_currentX()+1,player.get_currentY())){
//         //move the player down
//         move_down();
//     }
// }

void Game::control_player(){
/*********************************************************************
** Function: control_player()
** Description: takes player input and moves the player accordingly
** Parameters: none
** Pre-Conditions: user input, WASD
** Post-Conditions: player object is moved to an adjacent room where in the direction the user input
*********************************************************************/
    switch(control){
        case "W":
            move_up();
            break;
        case "A":
            move_left();
            break;
        case "D":
            move_right();
            break;
        case "S":
            move_down();
            break;
        case " W":
            //fire arrow up
            break;
        case " A":
            //fire arrow left
            break;
        case " D":
            //fire arrow right
            break;
        case " S"
    }
}