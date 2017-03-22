// Marya Poterek
// Interface for C4Col class
// C4Col.h
// CSE 20312

/* C4Col class interface that uses dynamic memory allocation. An object of this class is instantiated in the C4Board class using composition
*/

#ifndef C4COL_H
#define C4COL_H

#include<iostream>

class C4Col {

   public:
     C4Col(); //Default constructor
     ~C4Col(); //Destructor
     int isFull();  //Determines if column is full
     char getDisc(int);  //Returns requested element of private char array
     int getMaxDiscs();  //Returns max number of discs (num of rows)
     void addDisc(char);  //Adds char representing disc to next open slot in array

   private:
     int numDiscs; //Number of discs present in a column
     int maxDiscs; //Maximum number of discs in a column
     char * Discs; //Point at elements of array & is elements of array- not reserved memory space  
    
}; 

#endif                                   
