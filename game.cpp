#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

#include "room.h"
#include "wumpus.h"
#include "corpse.h"
#include "pit.h"
#include "gold.h"
#include "bat.h"
#include "game.h"

using namespace std;

Game::Game(){
/*********************************************************************
** Function: Game()
** Description: constructor for the game object
** Parameters: none
** Pre-Conditions: game object instantiated
** Post-Conditions: game object initialized
*********************************************************************/
    //this-> vector<vector<Room> > rooms;
    this-> mapSize = 0;
    this-> debugMode = false;
    this-> wumpusDead = false; //considering removing, i think it's redundant
    this-> goldGot = false;
    this-> control = "o"; 
    this-> retry =false;
    srand(time(NULL));
}

Game::~Game(){
/*********************************************************************
** Function:~Game()
** Description: destructor for the game object
** Parameters: none
** Pre-Conditions: game object goes out of scope
** Post-Conditions: memory cleared
*********************************************************************/
    for(int i = 0; i<event.size(); i++){
        delete event[i];
        event[i] = NULL;
    }
}

void Game::start_game(){
    /*********************************************************************
    ** Function: start_game()
    ** Description: starts the game
    ** Parameters: none
    ** Pre-Conditions: called in int main()
    ** Post-Conditions: game starts
    *********************************************************************/
    title_text();
}

void Game::title_text(){
    /*********************************************************************
    ** Function: title_text()
    ** Description: prints out the title
    ** Parameters: none
    ** Pre-Conditions: called in start_game
    ** Post-Conditions: calls main_menu
    *********************************************************************/
    cout << "===================HUNT THE WUMPUS===================" << endl;
    cout << "---------------------by Max Baker--------------------" << endl; 
    cout <<endl;
    main_menu();
}

void Game::main_menu(){
    /*********************************************************************
    ** Function: main_menu()
    ** Description: prints the main menu and allows the user to select an option from said menu
    ** Parameters: none
    ** Pre-Conditions: called in title_text()
    ** Post-Conditions: game starts
    *********************************************************************/
    int selection = 0;

    menu_options();
    cout << "Selection: ";
    cin >> selection;

    if(selection ==1){
        set_debugMode();
        set_mapSize();
    }else if (selection == 2){
        instructions();
    }else if (selection ==3){
        //end the program
    }else{
        cout << "Invalid input!" <<endl;
        main_menu();
    }
}

void Game::menu_options(){
    /*********************************************************************
    ** Function: menu_options()
    ** Description: outputs the options for the main menu
    ** Parameters: none
    ** Pre-Conditions: called from the main_menu function
    ** Post-Conditions: menu options printed
    *********************************************************************/
    cout << "Please make a selection:" << endl;
    cout << endl;
    
    cout << "1. Play game" <<endl;
    cout << "2. Instructions" << endl;
    cout << "3. End program" << endl;
    cout << endl;
}

void Game::instructions(){
    /*********************************************************************
    ** Function: instructions()
    ** Description: outputs instructions
    ** Parameters: none
    ** Pre-Conditions: called from main menu
    ** Post-Conditions: instructions printed
    *********************************************************************/
    cout << "In this remake of the classic 1973 computer game by Gregory Yob, you are an adventurer" << endl;
    cout << "who seeks to slay the Wumpus and steal its gold. You move by using the WASD keys when the" <<endl;
    cout << "prompts you for an input, and you shoot your bow by inputting 'space' followed by the WASD" <<endl;
    cout << "direction in which you want to shoot. You win the game by killing the wumpus, stealing its" <<endl;
    cout << "gold and making it back to your escape rope without dying. Good luck!" << endl;

    cout <<endl;
    main_menu();
}

void Game::press_enter(){

    /*function checks if the player pressed the input*/

    cin.get();

    /*getline(cin,temp); *do not know if this is necessary*/
}

void Game::set_mapSize(){
/*********************************************************************
** Function: set_mapSize()
** Description: gets a user input for the size of the dungeon map
** Parameters: none
** Pre-Conditions: game start
** Post-Conditions: mapSize is set to a user defined 
*********************************************************************/
    cout << "Enter a size to generate the map.";
    cin >> this->mapSize;
    if(mapSize < 4){
        cout << "Map size is too small!" << endl;
        set_mapSize();
    }
    if (mapSize > 30){
        cout << "Wow... that's pretty big. But if that's what you want, I am not going to stop you." <<endl;
    }
    game_flow();
}

int Game::get_mapSize(){
/*********************************************************************
** Function: get_mapSize()
** Description: returns mapSize
** Parameters: none
** Pre-Conditions: the game needs to check the size of the map
** Post-Conditions: returns mapSize
*********************************************************************/
    return this->mapSize;
}

void Game::generate_dungeon(){
/*********************************************************************
** Function: generate_dungeon()
** Description: creates a vector of rooms based on the user-determined mapSize
** Parameters: none
** Pre-Conditions: user determines mapSize
** Post-Conditions: vector of rooms created, memory allocated properly
*********************************************************************/
   define_events();
    rooms = vector <vector <Room> > (mapSize, vector<Room>(mapSize));
    int randX = -1;
    int randY = -1;

    for(int i = 0; i < 7; ++i){
        //find empty room
        do{
            randX = randomize_position();
            randY = randomize_position();
        }while(!rooms[randX][randY].is_Empty());
        
        rooms[randX][randY].set_event(event.back());
        rooms.at(randX).at(randY).set_position(randX,randY);
        event.pop_back();
    }
}



void Game::define_events(){
    /*********************************************************************
    ** Function: define_events()
    ** Description: defines the events within the events vector
    ** Parameters: none
    ** Pre-Conditions: events vector defined
    ** Post-Conditions: events instantiated
    *********************************************************************/
    event.push_back(new Wumpus());
    event.push_back(new Gold());
    event.push_back(new Bat());
    event.push_back(new Bat());
    event.push_back(new Pit());
    event.push_back(new Pit());
    event.push_back(new Corpse());
}

int Game::randomize_position(){
/*********************************************************************
** Function: randomize_position()
** Description: generates a random number from 0 to the mapSize - 1
** Parameters: none
** Pre-Conditions: an object needs to be placed in a room
** Post-Conditions: random number generated
*********************************************************************/
    int num = rand()%mapSize;
    return num;
}

void Game::set_player_spawn(){
/*********************************************************************
** Function: set_player_spawn()
** Description: randomizes the player's spawn coordinates
** Parameters: none
** Pre-Conditions: player object being placed into the game
** Post-Conditions: player object spawn point generated
*********************************************************************/
    int x = -1;
    int y = -1;

    do{
    x = randomize_position();
    y = randomize_position();
    }while(!rooms[x][y].is_Empty());

    //set player x
    player.set_startX(x);
    player.set_currentX(x); 

    //set player y
    player.set_startY(y);
    player.set_currentY(y);

}

void Game::draw_map(){
/*********************************************************************
** Function: draw_map
** Description: draws a grid with dimensions equal to the user specified mapSize
** Parameters: none
** Pre-Conditions: valid mapSize value set by the user
** Post-Conditions: map drawn
*********************************************************************/
    int i = 0;

    while(i<mapSize){
        for(int j = 0; j<mapSize; j++){
            // cout << "|" << "  ";
            cout<< "+---";
        }
        cout << "+";
        cout << endl;

        for (int k =0; k<mapSize; k++){
            if(get_debugMode() == false){
            cout << "|" << "  ";
            }else if (get_debugMode()==true){
                cout << "|" << " ";
                rooms.at(i).at(k).print_room();
                //cout << " ";
            }
            if((player.get_currentX()==i)&&(player.get_currentY()==k)){
                cout << "*";
            }else{
                cout <<" ";
            }

        }

        cout<<"|";
        cout << endl;
        i++;
    }
    if(i==mapSize){
        for(int m =0; m<mapSize; m++){
            cout << "+---";
        }
        cout << "+";
        cout <<endl;
    }
}
void Game::player_died(){
    /*********************************************************************
    ** Function: player_died()
    ** Description: handles the player's death
    ** Parameters: none
    ** Pre-Conditions: player is killed
    ** Post-Conditions: user is prompted with a menu of whether they want to continue or not
    *********************************************************************/
    int selection = 0;

    death_menu();
    cin >> selection;

    if(selection == 1){
        this->retry = true;
        game_flow();
    }else if(selection ==2){
        this->retry = false;
        set_mapSize();
    }else if (selection ==3){
        bad_ending();
    }else{
        cout << "Invalid selection" <<endl;
        player_died();
    }
}

void Game::death_menu(){
    /*********************************************************************
    ** Function: death_menu()
    ** Description: prints the menu options when the player dies
    ** Parameters: none
    ** Pre-Conditions: called when player dies 
    ** Post-Conditions: menu printed
    *********************************************************************/
    cout << "Try again?" << endl;
    cout << endl;

    cout << "1. Try again with the same dungeon layout"<< endl;
    cout << "2. Try again with a new dungeon layout" <<endl;
    cout << "3. Give up" << endl;
}

void Game::good_ending(){
    /*********************************************************************
    ** Function: good_ending()
    ** Description: prints out story text for when the player wins the game
    ** Parameters: none
    ** Pre-Conditions: player meets the win conditions
    ** Post-Conditions: game ends
    *********************************************************************/
    cout << "For the first time in history, an adventurer has devlved into the depths of the Wumpus's cave" <<endl;
    cout << "and returned to tell the tale. The village folk will tell tales of your incredible feat of courage" << endl;
    cout << "and your survival against all odds for generations to come. And while you will one day pass from" <<endl;
    cout << "this mortal plane and onto the Golden Shores, your story shall be immortalized forever in the pages" <<endl;
    cout << "of legend." << endl;

    cout << endl;
    cout << "YOU WIN!" << endl;
}
void Game::bad_ending(){
    /*********************************************************************
    ** Function: bad_ending()
    ** Description: prints out story text for when the player loses the game
    ** Parameters: none
    ** Pre-Conditions: player dies and chooses not to continue
    ** Post-Conditions: game ends
    *********************************************************************/
    cout <<"And so, yet another intrepid adventurer dared to venture into the cave of the wumpus, seeking" <<endl;
    cout << "gold and glory, never to return..." << endl;
    cout <<endl;
    cout << "GAME OVER!" <<endl;
}

void Game::win_menu(){
    /*********************************************************************
    ** Function: win_menu()
    ** Description: prompts the player about whether or not they want to play again after they win the game
    ** Parameters: none
    ** Pre-Conditions: player meets the game's win conditions
    ** Post-Conditions: the game runs again or the game ends
    *********************************************************************/
    cout << "Play again?" << endl;
    cout <<endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
}

void Game::player_wins(){
    /*********************************************************************
    ** Function: player_wins()
    ** Description: prompts the player about whether or not they want to play again after they win the game
    ** Parameters: none
    ** Pre-Conditions: player meets the game's win conditions
    ** Post-Conditions: the game runs again or the game ends
    *********************************************************************/
    int selection = 0;
    win_menu();
    cin >> selection;
    if(selection == 1){
        set_mapSize();
    }else if(selection == 2){
        //end program
    }else{
        cout << "Invalid input!" <<endl;
        player_wins();
    }
}


string Game::get_control(){
    /*********************************************************************
    ** Function: get_control()
    ** Description: returns the player's last input
    ** Parameters: none
    ** Pre-Conditions: player makes an input
    ** Post-Conditions: last input returned
    *********************************************************************/
    return this->control;
}

void Game::get_input(){
    /*********************************************************************
    ** Function: get_input()
    ** Description: allows the user to make inputs to interact with the game
    ** Parameters: none
    ** Pre-Conditions: 
    ** Post-Conditions: player does the action corresponding to their input
    *********************************************************************/
    getline(cin, this->control);
    control_player();
}

void Game::set_debugMode(){
    /*********************************************************************
    ** Function: set_debugMode()
    ** Description: allows the user to choose whether or not they want to run the program in debug mode
    ** Parameters: none
    ** Pre-Conditions: program starts
    ** Post-Conditions: debugMode is set to true or false depending on the user input
    *********************************************************************/
    string dbg_selection;
    
    cout << "Run game in debug mode? (Y/N)" <<endl;
    cin >> dbg_selection;

    if(dbg_selection == "y" ||dbg_selection == "Y"){
        this->debugMode = true;
        cout << "Debug mode enabled!" <<endl;
    }else if(dbg_selection == "n" || dbg_selection == "N"){
        this->debugMode=false;
    }
}

bool Game::get_debugMode(){
    /*********************************************************************
    ** Function: get_debugMode()
    ** Description: returns wthether the game is in debug mode or not
    ** Parameters: none
    ** Pre-Conditions: the game needs to check if debug mode is active
    ** Post-Conditions: true or false returned
    *********************************************************************/
    if(this->debugMode == false){
        return false;
    }else{
        return true;
    }
}

void Game::control_player(){
/*********************************************************************
** Function: control_player()
** Description: takes player input and moves the player accordingly
** Parameters: none
** Pre-Conditions: user input, WASD
** Post-Conditions: player object is moved to an adjacent room where in the direction the user input
*********************************************************************/
    if((this->control == "w" || this->control == "W") && (check_inBounds(player.get_currentX()-1, player.get_currentY())==true)){
        //move the player up
        move_up();
    }else if((this->control == "a" || this->control == "A") && (check_inBounds(player.get_currentX(),player.get_currentY()-1)==true)){
        //move the player to the left
        move_left();
    }else if((this->control == "d" || this->control == "D") && (check_inBounds(player.get_currentX(),player.get_currentY()+1)==true)){
        //move the player to the right
        move_right();
    }else if ((this->control == "s" || this->control == "S") && (check_inBounds(player.get_currentX()+1,player.get_currentY())==true)){
        //move the player down
        move_down();
    }else if(this->control == " W" ||this-> control == " w"){
        arrow_up();

    }else if(this->control == " A"|| this->control == " a"){
        arrow_left();

    }else if (this->control == " S" || this->control == " s"){
        arrow_down();

    }else if (this->control == " D" || this->control == " d"){
        arrow_right();

    }
}

void Game::set_wumpusPos(){
    /*********************************************************************
    ** Function: set_wumpusPos()
    ** Description: sets the value of the wumpus's position to its current location
    ** Parameters: none
    ** Pre-Conditions: game needs to check where the wumpus is
    ** Post-Conditions: wumpus's coordinates defined
    *********************************************************************/
    for(int i = 0; i<mapSize; i++){
        for(int j =0; j<mapSize; j++){
            if(rooms.at(i).at(j).get_eventType()=='w'){
                wumpX = i;
                wumpY = j;
                break;
            }
        }
    }
}
void Game::move_up(){
/*********************************************************************
** Function: move_up()
** Description: moves the player to the room above their current position
** Parameters: none
** Pre-Conditions: player inputs 'W'
** Post-Conditions: player moved to adjacent room
*********************************************************************/
    //rooms.at(player.get_currentX()).at(player.get_currentY()).set_event(' '); //sets to empty event
    player.set_currentX(player.get_currentX()-1);
    check_roomEvent(player.get_currentX(),player.get_currentY()); 
    //rooms.at(player.get_currentX()).at(player.get_currentY()).set_event('*');
}

void Game::move_left(){
/*********************************************************************
** Function: move_left()
** Description: moves the player to the room to the left of their current position
** Parameters: none
** Pre-Conditions: player inputs 'A'
** Post-Conditions: player moved to adjacent room
*********************************************************************/
    //rooms.at(player.get_currentX()).at(player.get_currentY()).set_event(' ');
    player.set_currentY(player.get_currentY()-1);
    check_roomEvent(player.get_currentX(),player.get_currentY()); 
    //rooms.at(player.get_currentX()).at(player.get_currentY()).set_event('*');
}

void Game::move_down(){
/*********************************************************************
** Function: move_down()
** Description: moves the player to the room below their current position
** Parameters: none
** Pre-Conditions: player inputs 'S'
** Post-Conditions: player moved to adjacent room
*********************************************************************/
    //rooms.at(player.get_currentX()).at(player.get_currentY()).set_event(' '); //sets to empty event
    player.set_currentX(player.get_currentX()+1);
    check_roomEvent(player.get_currentX(),player.get_currentY()); //define later
    //rooms.at(player.get_currentX()).at(player.get_currentY()).set_event('*');
}

void Game::move_right(){
/*********************************************************************
** Function: move_right()
** Description: moves the player to the room to the right of their current position
** Parameters: none
** Pre-Conditions: player inputs 'D'
** Post-Conditions: player moved to adjacent room
*********************************************************************/
    //rooms.at(player.get_currentX()).at(player.get_currentY()).set_event(' ');
    player.set_currentY(player.get_currentY()+1);
    check_roomEvent(player.get_currentX(),player.get_currentY()); 
    //rooms.at(player.get_currentX()).at(player.get_currentY()).set_event('*');    
}

void Game::arrow_up(){

    /*********************************************************************
    ** Function: arrow_up()
    ** Description: shoots an arrow upwards and checks if it hits the wumpus
    ** Parameters: none
    ** Pre-Conditions: player inputs " w"
    ** Post-Conditions: shoots and arrow and checks if it hits the wumpus
    *********************************************************************/

    if(player.has_arrows()==true){
        int arrowX = player.get_currentX();
        int arrowY = player.get_currentY();

        cout << "You fired an arrow!" << endl;\
        player.set_arrows(-1);

        for(int i = 0; i<4; i++){
            arrowX--;
            arrowY = player.get_currentY();
            if(check_inBounds(arrowX,arrowY)==true && rooms.at(arrowX).at(arrowY).get_eventType()=='w'){
                wumpus_dies();
                break;
            }else{
                wumpus_moves();
                break;
            }
        }
    }else{
        cout << "You have no arrows!" << endl;
    }
}

void Game::arrow_down(){
    /*********************************************************************
    ** Function: arrow_down()
    ** Description: shoots an arrow downwards and checks if it hits the wumpus
    ** Parameters: none
    ** Pre-Conditions: player inputs " s"
    ** Post-Conditions: shoots and arrow and checks if it hits the wumpus
    *********************************************************************/
    if(player.has_arrows()==true){
        int arrowX = player.get_currentX();
        int arrowY = player.get_currentY();

        cout << "You fired an arrow!" << endl;
        
        player.set_arrows(-1);

        for(int i = 0; i<4; i++){
            arrowX++;
            arrowY = player.get_currentY();
            if(check_inBounds(arrowX,arrowY)==true && rooms.at(arrowX).at(arrowY).get_eventType()=='w'){
                wumpus_dies();
                break;
            }else{
                wumpus_moves();
                break;
            }
        }
    }else{
        cout << "You have no arrows!" << endl;
    }
}

void Game::arrow_left(){
    /*********************************************************************
    ** Function: arrow_left()
    ** Description: shoots an arrow leftwards and checks if it hits the wumpus
    ** Parameters: none
    ** Pre-Conditions: player inputs " a"
    ** Post-Conditions: shoots and arrow and checks if it hits the wumpus
    *********************************************************************/
    if(player.has_arrows()==true){
        int arrowX = player.get_currentX();
        int arrowY = player.get_currentY();

        cout << "You fired an arrow!" << endl;
        player.set_arrows(-1);

        for(int i = 0; i<4; i++){
            arrowX = player.get_currentX();
            arrowY--;
            if(check_inBounds(arrowX,arrowY)==true && rooms.at(arrowX).at(arrowY).get_eventType()=='w'){
                wumpus_dies();
                break;
            }else{
                wumpus_moves();
                break;
            }
        }
    }else{
        cout << "You have no arrows!" << endl;
    }
}

void Game::arrow_right(){
    /*********************************************************************
    ** Function: arrow_right()
    ** Description: shoots an arrow rightwards and checks if it hits the wumpus
    ** Parameters: none
    ** Pre-Conditions: player inputs " d"
    ** Post-Conditions: shoots and arrow and checks if it hits the wumpus
    *********************************************************************/
    if(player.has_arrows()==true){
        int arrowX = player.get_currentX();
        int arrowY = player.get_currentY();

        cout << "You fired an arrow!" << endl;
        player.set_arrows(-1);

        for(int i = 0; i<4; i++){
            arrowX = player.get_currentX();
            arrowY++;
            if(check_inBounds(arrowX,arrowY)==true && rooms.at(arrowX).at(arrowY).get_eventType()=='w'){
                wumpus_dies();
                break;
            }else{;
                wumpus_moves();
                break;
            }
        }
    }else{
        cout << "You have no arrows!" << endl;
    }
}

void Game::wumpus_dies(){
    /*********************************************************************
    ** Function: wumpus_dies()
    ** Description: handles the wumpus's death and sets wumpusDead to true
    ** Parameters: none
    ** Pre-Conditions: player shoots an arrow and hits the wumpus
    ** Post-Conditions: wumpus deleated
    *********************************************************************/
    cout<<"You have slain the Wumpus!"<< endl;
    this->wumpusDead = true;
    rooms[this->wumpX][this->wumpY].set_event(NULL);
}

void Game::wumpus_moves(){
    /*********************************************************************
    ** Function: wumpus_moves()
    ** Description: handles the wumpus's movement
    ** Parameters: none
    ** Pre-Conditions: player shoots an arrow and misses
    ** Post-Conditions: generates a random number between 0 and 3 and if it's 0, the wumpus moves
    ** to a random coordinate within the cave
    *********************************************************************/
    if(wumpusDead!=true){
    cout << "You did not kill the Wumpus." <<endl;
    int num = rand()%4;
    if(num == 0){
        cout << "You can hear the Wumpus shift and turn in its sleep..." <<endl;
    }else if(num > 0){
        cout << "You can hear stomping from deep within the cave..." <<endl;
        //find empty room
        int randX = -1;
        int randY = -1;
        
        do{
            randX = rand()%mapSize;
            randY = rand()%mapSize;
        }while(!rooms[randX][randY].is_Empty());
        rooms[this->wumpX][this->wumpY].set_event(NULL);
        rooms[randX][randY].set_event(new Wumpus);
        check_roomEvent(player.get_currentX(),player.get_currentY());
    }

}
}
bool Game::check_inBounds(int xCoord, int yCoord){
/*********************************************************************
** Function: player_inBounds(int xCoord, int yCoord)
** Description: checks if the player is within the bounds of the map
** Parameters: int xCoord, int yCoord
** Pre-Conditions: player moves, check if the player can move in that direction
** Post-Conditions: return true if inbounds, false if not
*********************************************************************/
    if(xCoord > mapSize-1 || xCoord < 0 || yCoord > mapSize-1||yCoord<0){
        return false;
    }else{
        return true;
    }
}

void Game::check_roomEvent(int x, int y){
/*********************************************************************
** Function: check_roomEvent()
** Description: checks for an event within a room that the player moves into
** Parameters: none
** Pre-Conditions: checks if there is an event in that room
** Post-Conditions: calls the event's encounter function if there is an event in that room 
*********************************************************************/
    
    //these are to make the function simpler

    if(rooms.at(x).at(y).get_eventType()=='w'){
        //get wumpus encounter
        rooms.at(x).at(y).get_encounter();
        player.has_died();
    }else if (rooms.at(x).at(y).get_eventType()=='g'){
        if(this->goldGot == false){
            rooms.at(x).at(y).get_encounter();
            this->goldGot = true;
            rooms.at(x).at(y).set_event(NULL);
            cout << this->goldGot << " (debug message)" << endl;
        }
    }else if (rooms.at(x).at(y).get_eventType()=='p'){
        //pitfalls
        rooms.at(x).at(y).get_encounter();
        player.has_died();
    }else if(rooms.at(x).at(y).get_eventType()=='b'){
        //bats
        rooms.at(x).at(y).get_encounter();
        player.set_newPosition(randomize_position(),randomize_position());
        check_roomEvent(player.get_currentX(),player.get_currentY());
    }else if (rooms.at(x).at(y).get_eventType()=='c'){
        //corpse
        rooms.at(x).at(y).get_encounter();
        player.set_arrows(3);
        rooms.at(x).at(y).set_event(NULL);
    }else if(rooms.at(x).at(y).get_eventType() == ' '){
        //nothing is supposed to happen, this is a place holder statement to prevent a segmentation fault
    }
}

void Game::output_percepts(){
    /*********************************************************************
    ** Function: output_percepts()
    ** Description: outputs the percepts(gameMessages) of the object in an adjacent room if there is one
    ** Parameters: none
    ** Pre-Conditions: player moves to a new room
    ** Post-Conditions: percept printed to the console if there is an event in the adjacent room
    *********************************************************************/
    //adjacent room up
    if((check_inBounds(player.get_currentX()-1,player.get_currentY())==true) && (rooms.at(player.get_currentX()-1).at(player.get_currentY()).get_eventType()!= ' ')){
        rooms.at(player.get_currentX()-1).at(player.get_currentY()).get_percept();
        // cout << "This is a debug message!" << endl;
    }
    //adjacent room down
    if((check_inBounds(player.get_currentX()+1,player.get_currentY())==true) && (rooms.at(player.get_currentX()+1).at(player.get_currentY()).get_eventType()!= ' ')){
        rooms.at(player.get_currentX()+1).at(player.get_currentY()).get_percept();
        // cout << "This is a debug message!" << endl;
    }
    //adjacent room left
    if((check_inBounds(player.get_currentX(),player.get_currentY()-1)==true) && (rooms.at(player.get_currentX()).at(player.get_currentY()-1).get_eventType()!= ' ')){
        rooms.at(player.get_currentX()).at(player.get_currentY()-1).get_percept();
        // cout << "This is a debug message!" << endl;
    }
    //adjacent room right
    if((check_inBounds(player.get_currentX(),player.get_currentY()+1)==true) && (rooms.at(player.get_currentX()).at(player.get_currentY()+1).get_eventType()!= ' ')){
        rooms.at(player.get_currentX()).at(player.get_currentY()+1).get_percept();
        // cout << "This is a debug message!" << endl;
    }
}

void Game::reset_game(){
    /*********************************************************************
    ** Function: reset_game
    ** Description: reset's the player's spawn, sets goldGot and wumpusDead to false
    ** Parameters: none
    ** Pre-Conditions: player chooses to restart the game after death
    ** Post-Conditions: game resert
    *********************************************************************/
    this->goldGot=false;
    this->wumpusDead=false;
    player.respawn();
}

void Game::game_flow(){
    /*********************************************************************
    ** Function: game_flow()
    ** Description: handles the gameplay and everything that comes with it, loops until player dies
    ** or wins the game
    ** Parameters: none
    ** Pre-Conditions: game starts
    ** Post-Conditions: game ends
    *********************************************************************/
    if(this->retry!=true){
    generate_dungeon();
    set_player_spawn();
    reset_game();
    }
    set_wumpusPos();


    do{
       draw_map();
        output_percepts();
        cout << endl;
        cout << "Arrows: " << player.get_arrows() << endl;
        cout << "Position X: " << player.get_currentX()+1 << " Position Y: " << player.get_currentY()+1;

        if(get_debugMode()==true){
            cout <<endl;
            cout << "Escape Rope X: " << player.get_startX()+1 << " Escape Rope Y: " <<player.get_startY()+1 <<endl;
            if(wumpusDead!=true){
            cout << "Wumpus X: " << this->wumpX+1 << " Wumpus Y: " << this->wumpY+1;
            }
        }

        cout << endl;

        get_input();
        set_wumpusPos();
        

        if((this->wumpusDead == true)&&(this->goldGot == true)&&(player.get_currentX()==player.get_startX())&&(player.get_currentY()==player.get_startY())){
            good_ending();
            player_wins();
            break;
            }
    }while(player.isDead()!=true);
    if(player.isDead()==true){
    player_died();
    }
}