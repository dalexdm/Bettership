#include "battlefield.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
//#include <stoi.h>
using namespace std;

//helper tokenizer
std::vector<string> split(const std::string &s, char delim) {
    std::stringstream ss(s);
    std::string item;
    std::vector<string> elems;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

Battlefield::Battlefield()
{
    isMyTurn = true;
    for (int i = 0; i < 9; i ++) {
        for (int j = 0; j < 9; j++) {
            tiles[i][j] = 0;
        }
    }
    cout << endl;
    display();

    string userInput = "";

    cout << "Place ship with an orientation (h or v) and a location (A5 or C1)" << endl;
    cout << "Place patrol boat: " << endl;
    //Take input
    //use input to place patrol boat on tiles and initialize
    getline(cin, userInput);
    placeShip(userInput,2, "patrol boat!");

    display();
    cout << "Place sub: " << endl;
    //Take input
    //use input to place sub on tiles and initialize
    getline(cin, userInput);
    placeShip(userInput,3, "submarine!");

    display();
    cout << "Place destroyer: " << endl;
    //Take input
    //use input to place destroyer on tiles and initialize
    getline(cin, userInput);
    placeShip(userInput,3, "destroyer!");

    display();
    cout << "Place battleship: " << endl;
    //Take input
    //use input to place battleship on tiles and initialize
    getline(cin, userInput);
    placeShip(userInput,4, "battleship");

    display();
    cout << "Place carrier: " << endl;
    //Take input
    //use input to place carrier on tiles and initialize
    getline(cin, userInput);
    placeShip(userInput,5, "aircraft carrier!");

    display();

    //SHOULD WE ASSUME PLAYERS DONT PLACE OVERLAPPING SHIPS?
    //I MEAN I COULD WRITE A CHECK BUT THAT'D BE WORK
}

int checkLetter(char letter) {
    if (letter == 'A') {
        return 0;
    } else if (letter == 'B') {
        return 1;
    } else if (letter == 'C') {
        return 2;
    } else if (letter == 'D') {
        return 3;
    } else if (letter == 'E') {
        return 4;
    } else if (letter == 'F') {
        return 5;
    } else if (letter == 'G') {
        return 6;
    } else if (letter == 'H') {
        return 7;
    } else if (letter == 'I') {
        return 8;
    } else {
        return -1;
    }
}

char checkNumber(int letter) {
    if (letter == 0) {
        return 'A';
    } else if (letter == 1) {
        return 'B';
    } else if (letter == 2) {
        return 'C';
    } else if (letter == 3) {
        return 'D';
    } else if (letter == 4) {
        return 'E';
    } else if (letter == 5) {
        return 'F';
    } else if (letter == 6) {
        return 'G';
    } else if (letter == 7) {
        return 'H';
    } else if (letter == 8) {
        return 'I';
    } else {
        return -1;
    }
}

void Battlefield::placeShip(string input, int shipLength, string name) {

    std::vector<string> words = split(input, ' ');
    int lIndex = checkLetter(words[1].at(0));
    //minus 1 for 0 indexing
    int nIndex = atoi(&words[1].at(1)) - 1;

    //I PUT IN ERROR CHECKS BUT IDK HOW THIS WOULD WORK WITH THE REST OF THE FLOW
    //invalid
    /*if (i == -1 || j < 0 || j > 8) {
        cout << "Invalid Command. Please enter oritentation followed by" <<
        " location." << endl;
        return;
    }*/

    if (words[0] == "h") {
        for (int i = lIndex; i < lIndex + shipLength; i++) {
            tiles[i][nIndex] = 3;
        }
        Ship ship = Ship(lIndex, nIndex, shipLength,"h", name);
        ships.push_back(ship);
    } else if (words[0] == "v") {
        for (int i = nIndex; i < nIndex + shipLength; i++) {
            tiles[lIndex][i] = 3;
        }
        Ship ship = Ship(lIndex, nIndex, shipLength, name);
        ships.push_back(ship);
    } else {
        //I PUT IN ERROR CHECKS BUT IDK HOW THIS WOULD WORK WITH THE REST OF THE FLOW
       /* cout << "Invalid Command. Please enter oritentation followed by" <<
        " location." << endl;
        return; */
    }
}

void Battlefield::fire(string coords) {
    std::vector<string> words = split(coords, ' ');
    for (int i = 0; i < 3; i++) {
        cout << endl;
        int lIndex = checkLetter(words[i].at(0));
        int nIndex = atoi(&words[i].at(1)) - 1;
        if (tiles[lIndex][nIndex] != 0 && tiles[lIndex][nIndex] != 3) {
            cout << words[i] << " was already attempted!" << endl;
            continue;
        }
        int status = 0;
        int count = 0;
        while (status != 2 && count < 5) {
            status = ships[count].check(lIndex,nIndex);
            count++;
        }
        if (status == 0) cout << words[i] << " missed!" << endl;
        if (status == 2) cout << words[i] << " hit!" << endl;
        tiles[lIndex][nIndex] = status;
    }
}

Battlefield::~Battlefield()
{

}

string Battlefield::getString(int num) {
    switch (num) {
        case 0:
            return " ";
        break;
        case 1:
            return "0";
        break;
        case 2:
            return "X";
        break;
        case 3:
            if (isMyTurn) return "•";
            else return " ";
        break;
        default:
            return "?";
        break;
    }
}

void Battlefield::display() {
    string topBlock = "    |     |     |     |     |     |     |     |     |     |";
    string botBlock = "    |_____|_____|_____|_____|_____|_____|_____|_____|_____|";
    string front = "   |  ";
    string end = "  |";
    string pip = "  |  ";
    cout << "       A     B     C     D     E     F     G     H     I " << endl;
    cout << "     _____ _____ _____ _____ _____ _____ _____ _____ _____" << endl;
    for (int i = 0; i < 9; i++) {
        cout << topBlock << endl;
        cout << i + 1;
        cout << front;
        for (int j = 0; j < 9; j++) {
            cout << getString(tiles[j][i]);
            if (j != 8) cout << pip;
        }
        cout << end << endl;
        cout << botBlock << endl;
    }
    cout << endl;
}

void Battlefield::setTurn(bool turn) {
    isMyTurn = turn;
}

bool Battlefield::didLose() {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += ships[i].getLife();
    }
    return sum;
}
