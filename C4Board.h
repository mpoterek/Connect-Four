//Marya Poterek
//Interface for C4Board class
//C4Board.h
//CSE 20312

/* C4Board class interface that uses dynamic memory allocation and composition to create an object of C4Col
*/


#ifndef C4BOARD_H
#define C4BOARD_H

#include <iostream>
#include "C4Col.h"

class C4Board {

   public:
     C4Board(); //Default constructor
     ~C4Board(); //Destructor
     int checkWin(int); //Runs through board, passes discs to checkDisc
     bool checkDisc(int, int, char); //Checks each disc for winning conditions
     void display(); //Display current board
     void play(int); //Allows two players to play a game  
   
   private:
     int columns;
     C4Col *board; //Dynamic memory allocation, object of class C4Col
     


};

#endif
