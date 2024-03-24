#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

class Player{
    private:
        int playerStartPos_X; //player's X starting coordinate
        int playerStartPos_Y; //player's Y starting coordinate
        int playerPos_X; //player's current X coordinate
        int playerPos_Y; //player's current Y coordinate
        int arrows; //player's current number of arrows
        bool dead; //true when player dies
    public:

        Player(); //constructor
        ~Player(); //destructor

        bool isDead();
        void has_died();
        int get_startX();
        int get_startY();
        int get_currentX();
        int get_currentY();

        void set_startX(int x);
        void set_startY(int y);
        void set_currentX(int x);
        void set_currentY(int y);
        void set_newPosition(int x, int y);
        void respawn();

        int get_arrows();
        void set_arrows(int num);
        bool has_arrows();
};

#endif