# Connect-Four
Connect 4 game for two players (CSE 20312)


From the user's perspective, this program is very simple. Each user (player 1 or 2) is prompted in turn to add a piece (X or O) to the board in a column of his or her choice. The board is then printed out with the user's piece placed in it and the next user can decide which column to place his or her piece in. The two players continue to alternate until one of them achieves four pieces in a row and is declared a winner, or all 42 spaces on the board have been filled. At each opportunity for user input, there are error checks present to keep the game flowing smoothly if a column name outside of the board's range is entered, the user is asked to enter a valid column name and will continue to be asked until he/she does so. Additionally, if the player tries to place a piece in an already-full row, he/she will be told that the row is full, and the next player will take his/her turn. 
Internally, the program uses composition and is structured upon two classes: C4Board and C4Col. An object of the latter is instantiated and constructed in the latter's implementation and interface, essentially building a game board by establishing an array of class C4Col objects, which in turn are one-dimensional arrays that form each column of the board. An object of class C4Board is instantiated in main, which constructs the C4Col objects in turn when its own constructor is run. 
From main, the object c of class C4Board is created. While conditions for the continuance of the game remain true (a win has not been declared and the turn count is less than 42, the number of spaces on the board), member functions to play the game, display the board, and check for a win will continue to be called on the object c. In the C4Board implementation, the display function prints the board and its contents, the play function prompts the user to choose a column and verifies the validity of the column number entered, and passes that number to the addDisc function in the C4Col class. The checkWin function runs through the entire board and passes each character at each location in the board along with the piece just played to the checkDisc function, which facilitates the determination of the winner.
To do so, the checkDisc function has a set of if statements that take in each position on the board and the piece just played and checks to see if each position on the board is part of a win, or four pieces in a row. Since the checkWin function runs through the entire board each time a piece is played, the whole board is checked for a win every turn and the board can be checked only from the bottom up. To check for a vertical win, an if statement compares the value of the board (the char there) at the location passed in and each of the three elements above it to the char value of the disc passed in, either X or O depending on the turn value (i.e. if it is player 1 or player 2). The same essential methodology is applied to the remaining directions: horizontal, diagonal with positive slope, and diagonal with negative slope, but with a different three spaces checked relative to the original location passed in, of course. Additionally, the if statements include checks to limit the scope of the board-checking procedure to the board itself, to avoid memory access issues and segmentation errors. After these checks have taken place, the checkDisc returns the bool noWin as true, if no win has been found, or false if one of the if/if else statements have found four pieces in a row. 
From several places in the C4Board class implementation, C4Col member functions are called to check if a column (or C4Col object, which is an array of chars) is full, to retrieve a specific element, to return the number of discs possible in a column, or to add a disc/game piece to a column. These functions are relatively straightforward, and are essentially all get/set functions, but are critical to game play as they provide access to the pieces that actually make up the board. Dynamic memory allocation is used in both this C4Col class and the C4Board class, which allows the constructor to allocate only the amount of memory needed for the program. Because of this, a deconstructor was needed for each class to allow that memory used by the program to be deallocated once the variables involved are out of scope. Default deconstructors only deallocate member objects, so the use of delete ensures that the pointers to the objects, which are necessary in dynamic memory management, are removed from memory as well. 
	To verify the program, edge cases and invalid input were tested to ensure that the program could handle them appropriately. At every opportunity for user input, different types of invalid input were tested to ensure an error message would appear and game play could continue. For instance, column numbers not found on the board were entered, or the number of columns that were already full were entered. The program was able to recognize and deal with this invalid input correctly, and continue the game. In addition to this, every direction in which winning conditions were tested on varying places in the board and with both game pieces (X and O) to ensure the program's ability to assert a winner was functioning correctly. 
