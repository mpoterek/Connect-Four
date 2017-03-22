//Marya Poterek
//Main driver for C4 classes
//C4main.cpp
//CSE 20312

/* Main driver for both C4Col and C4Board classes, which instantiates object of class C4Board (and thus multiple objects of class C4Col via composition). This program calls member functions that facilitate game play, and directs the user's experience.
*/

#include<iostream>
#include "C4Board.h"

using namespace std;


int main() {
   int turn = 1; //Begins with Player 1
   int win = 0;
   C4Board c; //Object of class C4Board, also constructs 7 objects of class C4Col
   
   cout << "Welcome to Connect 4! Player 1 goes first!" << endl;
 
    while (turn < 42 && win == 0) {
      c.play(turn); //Play game, links to functions that place piece and check for win, etc. 
      c.display(); //Prints board after each turn
      win = c.checkWin(turn);
      turn++; //Increments after each play
    }
    return 0;
}
