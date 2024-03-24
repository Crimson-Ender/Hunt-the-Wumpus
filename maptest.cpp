#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

/*this program is not included in the Hunt the Wumpus game code. This program is here just to test
out possible implementations for the dungeon grid generator.*/

int mapSize;

void get_mapSize(){
    cin >> mapSize;
}

void dungeon_map(){
    int i = 0;

    while(i<mapSize){
        for(int j = 0; j<mapSize; j++){
            // cout << "|" << "  ";
            cout<< "+---";
        }
        cout << "+";
        cout << endl;

        for (int k =0; k<mapSize; k++){
            cout << "|" << "   ";
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


int main(){
    get_mapSize();
    dungeon_map();
    main();
    return 0;
}