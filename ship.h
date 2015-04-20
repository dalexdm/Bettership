#ifndef SHIP_H
#define SHIP_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Ship
{
public:
    Ship(int x, int y, int length, string h, string name);
    Ship(int x, int y, int length, string name);
    Ship();
    ~Ship();
    int getLife();
    int check(int x, int y);

private:

    std::vector<std::pair<int,int> > pieces;
    int life;
    string name;

};

#endif // SHIP_H
