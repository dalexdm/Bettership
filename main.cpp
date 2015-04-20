#include <iostream>
#include <battlefield.h>
#include <string>

using namespace std;

int main()
{
    string userInput;
    cout << endl << endl;
cout <<"                                      |__" << endl;
cout <<"                                      ||/" << endl;
cout <<"                                      ---" << endl;
cout <<"                                    / | [" << endl;
cout <<"                             !      | |||" << endl;
cout <<"                           _/|     _/|-++'" << endl;
cout <<"                       +  +--|    |--|--|_ |-" << endl;
cout <<"                    { /|__|  |/|__|  |--- |||__/" << endl;
cout <<"                    +---------------___[}-_===_.'____                 " << endl;
cout <<"                ____`-' ||___-{]_| _[}-  |     |_[___|==--                  _" << endl;
cout <<"__..._____--==/___]_|__|_____________________________[___|==--____,------' .7" << endl;
cout <<"|                                                      S.S. BOOTYLICIOUS   /" << endl;
cout <<"|   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   / " << endl;
cout <<"|________________________________________________________________________/" << endl << endl;
cout << "                      WELCOME TO C++ BATTLESHIP!" << endl;
    getline(cin, userInput);
    cout << "Player 1: Place ships...";
    Battlefield p1 = Battlefield();
    //This should prompt a player on its own.
    //clear the screen, buncha endlines
    cout << string(75, '\n');

    cout << "Player 2: Place ships...";
    Battlefield p2 = Battlefield();
    //clear the screen, buncha endlines
    cout << string(75, '\n');

    bool p1Lost = false;
    bool p2Lost = false;

    while (1) {
        p1.setTurn(true);
        p2.setTurn(false);
        cout << "Player 1 turn:" << endl;
        while(1) {
            p2.display();
            cout << "Enter 3 coordinates to strike! (i.e. 'A5 C1 G9')" << endl;
            cout << "Or type 'status' to see your own board" << endl;
            getline(cin, userInput);
            if (userInput != "status") break;
            p1.display();
            cout << "Press enter to return to your gun when you are finished!" << endl;
            getline(cin, userInput);
        }
        p2.fire(userInput);
        p2.display();
        cout << "Player 2, take a seat and hit enter when ready!" << endl;
        getline(cin, userInput);
        //clear the screen, buncha endlines
        cout << string(75, '\n');

        p1.setTurn(false);
        p2.setTurn(true);
        cout << "Player 2 turn:" << endl;
        while(1) {
            p1.display();
            cout << "Enter 3 coordinates to strike! (i.e. 'A5 C1 G9')" << endl;
            cout << "Or type 'status' to see your own board" << endl;
            getline(cin, userInput);
            if (userInput != "status") break;
            p2.display();
            cout << "Press enter to return to your gun when you are finished!" << endl;
            getline(cin, userInput);
        }
        p1.fire(userInput);
        p1.display();
        cout << "Player 1, take a seat and hit enter when ready!" << endl;
        getline(cin, userInput);
        //clear the screen, buncha endlines
        cout << string(75, '\n');

        if (p1Lost && p2Lost) {
            cout << "It's a draw!" << endl;
            getline(cin, userInput);
            return 0;
        }
        if (p1Lost) {
            cout << "Player 2 wins!" << endl;
            getline(cin, userInput);
            return 0;
        }
        if (p2Lost) {
            cout << "Player 1 wins!" << endl;
            getline(cin, userInput);
            return 0;
        }
    }


}

