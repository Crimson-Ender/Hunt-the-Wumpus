#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

#include "player.h"
#include "event.h"
#include "room.h"

class Game{
    private:
        vector<vector<Room> > rooms;
        vector<Event*> event;
        Player player;
        int mapSize; //size of the map
        int wumpX;
        int wumpY;
        bool debugMode; //determines whether cheat view is on
        bool wumpusDead; //true if player has killed the wumpus
        bool goldGot; //true if the player
        bool won; //true if player got the gold and killed the wumpus
        bool retry;
        string control;
    public:
        Game(); //constructor
        ~Game(); //deconstructor

        void start_game();
        void set_mapSize();
        int get_mapSize();
        void generate_dungeon();
        void define_events();
        int randomize_position();
        void set_player_spawn();
        void draw_map();
        void shoot_arrow();
        void player_died();
        void player_wins();
        string get_control();
        void get_input();
        void control_player();
        void wumpus_moves();
        void check_roomEvent(int x, int y);
        bool check_inBounds(int xCoord, int yCoord);
        bool get_debugMode();
        void set_debugMode();
        void title_text();
        void main_menu();
        void menu_options();
        void instructions();
        void press_enter();
        void set_wumpusPos();
        void wumpus_dies();
        void output_percepts();
        void death_menu();
        void good_ending();
        void bad_ending();
        void win_menu();
        void reset_game();
        //player movement handlers
        void move_up();
        void move_left();
        void move_down();
        void move_right();

        //arrow handlers
        void arrow_up();
        void arrow_down();
        void arrow_left();
        void arrow_right();
        //need function to generate rooms
        
        void game_flow();
};

#endif