#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H
#include "ship.h"
#include <string>

using namespace std;
class Battlefield
{
public:
    Battlefield();
    ~Battlefield();
    void placeShip(string input, int shipLength, string name);
    void display();
    void fire(string coords);
    void getShips();
    string getString(int num);
    bool didLose();

    void setTurn(bool turn);
private:
    // 0 = unused, 1 = miss, 2 = hit, 3 = ship
    //IM USING CONVENTION FIRST IS LETTER, SECOND NUMBER
    int tiles[9][9];
    vector<Ship> ships;
    bool isMyTurn;



};

#endif // BATTLEFIELD_H
