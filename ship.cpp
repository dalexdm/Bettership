#include "ship.h"
#include <string>
using namespace std;

//2 separate constructors for vert/horiz ships
//horizontal
Ship::Ship(int x, int y, int length, string h, string name)
{
    //will be called when placing ships
    for (int i = x; i < x + length; i++) {
        pieces.push_back(pair<int,int>(i,y));
    }
    this->name = name;
    //?? v
    h = "";
    life = length;
}
//vertical
Ship::Ship(int x, int y, int length, string name) {
    for (int i = y; i < y + length; i++) {
        pieces.push_back(pair<int,int>(x,i));
    }
    //?? v
    this->name = name;
    life = length;
}

Ship::Ship() {

}

Ship::~Ship()
{

}

int Ship::check(int x, int y) {
    //if coords are in our vector of pairs, return 2(hit), then lose life
    //otherwise return 1(miss)
    if(std::find(pieces.begin(), pieces.end(), pair<int,int>(x,y)) != pieces.end()) {
        if (life > 0) life -= 1;
        if (life == 0) cout << "You sunk the opponent's " << name << endl << endl;
        return 2;
    } else {
        return 1;
    }
}

int Ship::getLife() {
    return life;
}

