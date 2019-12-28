/// Include the header file created for this assignment
#include "TicTacToe.h"

/**
 * @brief This is the main function to run the game
 * 
 */
int main(){
    // Utilize srand and time to seed the random number generator
    srand(time(0));
    // Create a humanPlayer instance
    humanPlayer Tony("Tony");
    // Create a C3P0Player instance
    computerPlayer C3P0 ("C3P0");
    // Create an instance of the board
    Board game;
    // Create strings to hold the names
    string humanName, C3P0Name;
    // Get the names from the Player objects
    humanName = Tony.getName();
    C3P0Name = C3P0.getName();
    /**
     * @brief Declare all ints needed
     *  C3P0R0W, C3P0Column: The row and column C3P0 needs to make a move
     *  humanRow, humanColumn: The row and column the human needs to make a move
     *  canMove: an int to determine if the current move is valid or not
     */
    int C3P0Row, C3P0Column, 
        humanRow, humanColumn,
        canMove; 

    // Alert to the beginning of a game
    cout << "BEGINNING TIC TAC TOE GAME " << "\n" << endl;


    /** While true technically executes forever, so continue this loop until
    the program exits. These comments have been left as Doxygen comments for
    documentation purposes. **/
    while (true){
        /// Print out the human's name, and initiate their turn
        cout << humanName << "'s move." << endl;
        /// Utilize a do while loop to ensure the move is valid
        do{
            /// Collect the row and column to play the human move
            humanRow = Tony.collectRowMovement();
            humanColumn = Tony.collectColMovement();
            /// Determine if the move is valid
            canMove = game.checkMove(humanRow, humanColumn, 'O');            
        } while (canMove != 1); /// Keep going until the move is valid  
        /// Once it is, play the move
        game.placeMove(humanRow, humanColumn, 'X');
        /// Print out the board
        game.printBoard();
        /// Check to see if anybody has won, or if it is a tie
        game.checkStatus(humanName);

        /// Now repeat the process for the computer
        /// Print out the computer's name, and initiate their turn
        cout << C3P0Name << "'s move." << endl;
        /// Utilize a do while loop to ensure the move is valid
        do{
            /// Collect the row and column to play the computer move
            C3P0Row = C3P0.generateRowMovement();
            C3P0Column = C3P0.generateColMovement();
            /// Determine if the move is valid
            canMove = game.checkMove(C3P0Row, C3P0Column, 'O');            
        } while (canMove != 1); /// Keep going until the move is valid
        /// Once it is, play the move
        game.placeMove(C3P0Row, C3P0Column, 'O');
        /// Print out the board
        game.printBoard();
        /// Check to see if anybody has won
        game.checkStatus(C3P0Name);

        /** Assuming the program has not exited, continue on
        in the while(true) loop **/
    } // end while

} // end main