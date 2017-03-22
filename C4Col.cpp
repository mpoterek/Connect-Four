//Marya Poterek
//Implementation for C4Col class
//C4Col.cpp
//CSE 20312

/*C4Col class implementation that uses dynamic memory allocation to create columns in which the game pieces will be stored. Member functions are called from main (as part of board object) as well as from within this implementation file. This program facilitates checking if a column is full, returning an element from a given place in a column, and adding new pieces to the board
*/

#include <iostream>
#include "C4Col.h"

using namespace std;

C4Col::C4Col() { //Default constructor using dynamic memory allocations
   numDiscs = 0;
   maxDiscs = 6;
   Discs = new char [maxDiscs];
   for( int i=0; i<= (maxDiscs-1); i++) {
     Discs[i] = ' ';
   }
}

C4Col::~C4Col() { //Deconstructor
   delete []Discs; //Deletes whole array, not just first element 
} 

int C4Col::isFull() { //Returns value to addDisc 
   if (numDiscs >= maxDiscs) { //If column is full returns 1
     return 1;
   }
   else  //If column is not full returns 2
     return 2;
}

char C4Col::getDisc(int element) {  //Returns value at given element of column array
   if (element >= 0 && element <= 5) { //No way for incorrect element value to be entered, but safeguard implemented     
      return Discs[element];
   }
   else 
     cout << "Improper memory access" << endl;
     return 0;
}

int C4Col::getMaxDiscs() { //Returns greatest number of discs possible in a column
   return maxDiscs;
}

void C4Col::addDisc(char disc) { //Checks if column is full before adding disc
   int full = isFull();
   if (full == 1) {
     cout << "Column full, next player." << endl;
   }
   else
     Discs[numDiscs++] = disc;  
}
