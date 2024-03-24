#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include "room.h"

using namespace std;

Room::Room(){
    this->inRoom = NULL;
}

Room::~Room(){
    if (this->inRoom != NULL){
        delete this->inRoom;
        this->inRoom = NULL;
    }
}

bool Room::is_Empty() const{
    return this->inRoom == NULL;
}

void Room::set_event(Event* new_e){
    this->inRoom = new_e;
}

void Room::print_room() const{
    if(is_Empty()){
        cout << " ";
    }else{
        this->inRoom ->display_eventType();
    }
}

Event* Room::get_event(){
    return this->inRoom;
}

char Room::get_eventType(){
    if(this->inRoom !=NULL){
    return this->inRoom -> get_eventType();
    }else{
        return ' ';
    }
}

void Room::get_encounter(){
    this->inRoom->encounter();
}

void Room::set_position(int x, int y){
    this->inRoom -> set_position(x, y);
}

int Room::get_positionX(){
    this->inRoom->get_positionX();
}

int Room::get_positionY(){
    this->inRoom->get_positionY();
}

bool Room::check_eventType(char eventType){
    this->inRoom->check_eventType(eventType);
}

void Room::get_percept(){
    cout << this->inRoom->get_gameMessage() << endl;
}