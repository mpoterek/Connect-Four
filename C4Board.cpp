//Marya Poterek
//Implementation for C4Board class
//C4Board.cpp
//CSE 20312

/* Implementation for the C4Board class, which manipulates the object of class C4Col called 'board'. Member functions in this program are called from main and implemented here, with calls to C4Col member functions and access to private variables. This program facilitates board display, game play, and establishes win conditions. 
 */

#include <iostream>
#include "C4Board.h"


using namespace std;

C4Board::C4Board() { //Constructor
   columns = 7;
   board =  new C4Col [columns]; //Dynamic memory allocation
}

C4Board::~C4Board() { //Destructor for dynamic memory allocation
   delete []board;
}

void C4Board::display() { //Displays board by iterating through board and printing each element
   cout << " _______________" << endl;
   for (int row = board[0].getMaxDiscs()-1; row >=0; row--) {
     cout << " ";
      for (int col = 0; col < columns ; col++) { 
        cout << "|" << board[col].getDisc(row); 
      }
      cout << "|\n";
   }
   cout << " ---------------" << endl; //Formatting and labels
   cout << "  1 2 3 4 5 6 7  " << endl;
}

void C4Board::play(int turn) {
   int colnum;
   if (turn % 2 == 1) { //Player 1, X
     cout << "Player 1: What column would you like to add X to?" << endl;
     cin >> colnum;
     if (colnum > 7 || colnum < 1) { //Checks validity of column input
       cout << "Please enter a valid column name: " << endl;
       cin >> colnum;
     }
     board[colnum-1].addDisc('X');
   }
   else  { //Player 2, O
     cout << "Player 2: What column would you like to add O to?" << endl;
     cin >> colnum;
       if (colnum > 7 || colnum < 1) { //Checks validity of column input
         cout << "Please enter a valid column name: " << endl;
         cin >> colnum;
       }
     board[colnum-1].addDisc('O');
   }
}

int C4Board::checkWin(int turn) { //Passes each disc location and type to checkDisc
   char piece;  //X or O
   bool noWin = true;

   if( turn % 2 ==1)
     piece = 'X'; //Player 1
   else
     piece = 'O'; //Player 2
   for (int row = board[0].getMaxDiscs()-1; row >=0; row--) { //Iterates through entire board
     for (int col = 0; col < columns ; col++) {
       noWin  = checkDisc(row, col, piece); //Calls checkDisc function
      if (noWin == false) {
         cout << piece << " is the winner!" << endl; //Winner declared, break from for loops
         break;
       }
     }
   }
   if(noWin == false){ //If win declared, 1 returned to main and game ended 
      return 1;
   }
   else // 0 returned to main and game continues
     return 0;
}

bool C4Board::checkDisc(int row, int col, char disc) { //Checks board for winning conditions with given piece
   bool noWin;
   
   //Vertical conditions with memory access limitations
   if (row+3 <= 5 && disc==board[col].getDisc(row) && disc==board[col].getDisc(row+1) && disc==board[col].getDisc(row+2) && disc==board[col].getDisc(row+3)) {
    noWin = false;
   } 

   //Horizontal conditions with memory access limitations
   else if (col+3 <= 6 && disc==board[col].getDisc(row) && disc==board[col+1].getDisc(row) && disc==board[col+2].getDisc(row) && disc==board[col+3].getDisc(row)) {
     noWin = false;
   } 

   //Positive diagonal conditions with memory access limitations
   else if (row+3 <= 5 && col+3 <= 6 && disc==board[col].getDisc(row) && disc==board[col+1].getDisc(row+1) && disc==board[col+2].getDisc(row+2) && disc==board[col+3].getDisc(row+3)) {
    noWin = false; 
   }
   
   //Negative diagonal conditions with memory access limitations
   else if (row+3 <= 5 && col-3 >= 0 && disc==board[col].getDisc(row) && disc==board[col-1].getDisc(row+1) && disc==board[col-2].getDisc(row+2) &&disc==board[col-3].getDisc(row+3)) {
     noWin = false;
   }

   else { //If win conditions not achieved
     noWin = true;
   } 

   return noWin;
}
  

