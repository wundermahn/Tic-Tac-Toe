/**
 * This header file includes class definitions for:
 * Player, humanPlayer, computerPlayer
 * Board
 * 
 * Included in these classes are both member data and relevant functions
 * All comments have been attempted to have been done in Doxygen notation.
 *
 * \author $Author: Anthony (Tony) Kelly
 *
 * \version $Revision: 2.0 $
 *
 * \date $Date: 09/15/2019 $
 *
  *
 * $Id: Kelly_TicTacToe.html,v 2.0 09/15/2019 bv Tony Kelly $
 *
 */

/// Used for input and output operations like cout, cin
#include <iostream>
/// Used for random number generator as displayed in lecture
#include <random>
/// Needed for seeding the generator
#include <ctime>
/// Using standard namespace
using namespace std;

/// Create a parent Player class
class Player
{
    /// Create public functions
    public:

    /**
     * @brief This is the constructor for a player object.
     * This constructs a new player object and sets the name attribute of the object
     * to whichever value is passed in via the name parameter
     * 
     * @param a string for the name of the player
     */
    explicit Player(string name){
        this->name = name;
    }

    /**
     * @brief This is (also) the constructor for a player object
     *  An example of constructor / function overloading, this is a blank constructor
     */
    explicit Player(){
        // balnak
    }
    /**
     * @brief A getter function to get the name
     * 
     * @return string name, which is a class attribute
     */
    string getName(){
        return name;
    }

    /**
     * @brief A setter function to set the Name object
     * 
     * @param newname is the passed in value if you want
     *  to change the name
     */
    void setName(string newname){
        name = newname;
    }

    /**
     * @brief Protected member data
     * The name, and the column and row values
     * the player will try to play tic tac toe with
     * 
     */
    protected:
    string name;
    int col, row;

}; /// < End of class Player

/**
 * @brief An inherited subclass of Player, humanPlayer
 * 
 */
class humanPlayer : public Player
{
    /// Create public functions
    public:

    /**
     * @brief This is the constructor for a humanPlayer object
     * Construct a new humanPlayer object
     * 
     * @param name a string for the name of the humanPlayer
     */
    explicit humanPlayer(string name){
        this->name = name;
    }

    /**
     * @brief 
     * Collects user input for the location of the row to play
     * It does this via a commmand line input (cin), after alerting the user to enter
     * something via a command line output (cout)
     * 
     * @return int that is the row to play in tic tac toe 
     */
    int collectRowMovement(){
        // alert the user that input is needed
        cout << "Please input your row move: " << endl;
        // collect it
        cin >> row;
        // return it
        return row;
    }

    /**
     * Collects user input for the location of the column to play
     * It does this via a commmand line input (cin), after alerting the user to enter
     * something via a command line output (cout)
     * 
     * @return int that is the column to play in tic tac toe
     */
    int collectColMovement(){
        // alert the user that input is needed
        cout << "Please input your column move: " << endl;
        // collect it
        cin >> col;
        // return it
        return col;
    }    

}; //End of subclass humanPlayer

/**
 * @brief An inherited subclass of Player, computerPlayer
 * 
 */
class computerPlayer : public Player
{
    /// Create public functions
    public:
    
    /**
     * @brief This is the constructor for a computerPlayer object
     * Construct a new computerPlayer object
     * 
     * @param name a string for the name of the computerPlayer
     */
    explicit computerPlayer(string name){
        /// Set the name to the name passed in
        this->name = name;
    }

    /**
     * @brief 
     * Generates random number between 0 and 2 for the location
     * of the row to play. Utilizes rand() to create a random
     * number between 0 and 2 (inclusive)
     * 
     * @return int that is the row to play in tic tac toe
     */
    int generateRowMovement(){
        /// Create random number
        row = rand() % 3;
        /// Return it
        return row;
    }

    /**
     * Generates random number between 0 and 2 for the location
     * of the column to play. Utilizes rand() to create a random
     * number between 0 and 2 (inclusive)
     * 
     * @return int that is the column to play in tic tac toe
     */
    int generateColMovement(){
        /// Create random number
        col = rand() % 3;
        /// Return it
        return col;
    }

}; // End of subclass computerPlayer

/**
 * @brief The Board class is the class which
 * actually contains the tic tac toe grid and
 * much of the logic of the game itself (such as error 
 * handling and move placement)
 * 
 */
class Board
{
    // Public functions and member data
    public:
    // Blank constructor
    explicit Board(){

    } // end board

    /**
     * @brief 
     * This functions prints out the board, with horizontal and 
     * vertical lines as required. In the "spoces" are the locations of the 2d
     * char array state which holds those values
     * 
     * @param state is a 2d char array which holds, essentially a grid, of the
     * board and the moves.
     */
    void printBoard(){
        cout << "       " << state[0][0] << "  |  " << state[0][1] << "  |  " << state[0][2] << endl;
        cout << "     -----+-----+-----" << endl;
        cout << "       " << state[1][0] << "  |  " << state[1][1] << "  |  " << state[1][2] << endl;
        cout << "     -----+-----+-----" << endl;
        cout << "       " << state[2][0] << "  |  " << state[2][1] << "  |  " << state[2][2] << endl;
        cout << "     -----+-----+-----" << endl;  
    } // end printboard
  
    /**
     * @brief 
     * This functions places a move on the "grid",
     * which is a 2d char array explained more in depth later on. 
     * 
     * @param row is an int of the row (0-2) to place the character
     * @param col is an int of the column (0-2) to place the character
     * @param move is which character is being placed
     */
    void placeMove(int row, int col, char move){
        // Change the "state" or the grid's location to be the move
        state[row][col] = move;        
    } // end of placeMove

    /**
     * @brief This function checks the legality of a move
     * It ensures the following:
     * 1) That the move is within bounds (0-3)
     * 2) That the move is not currently overwriting a space
     * 3) And that the move is an X or an O
     * 
     * 
     * @param row an int to specify the row to place a move
     * @param col an int to specify the column to place a move
     * @param move a char that is the move to be placed
     * @return int returns to check the validity of the move
     * 1 is valid, 0 is invalid. 0 is accompanied with a console print out
     */
    int checkMove(int row, int col, char move){
        if (
            // Check specified conditions
            // The row and columns are 0-2 inclusive
            (row >= 0 && row < 3 && col >= 0 && col < 3)
            // It is a "blank" space
            && (state[row][col] == '.')
            // It is a legal character
            && (move == 'O' || move == 'o' || move == 'X' || move == 'x')){
            // If all are true (AND), return 1
            return 1;
        }else{
            // Otherwise, alert the player and return 0
            cout << "Invalid move." << "\n" << endl;
            return 0;
        } // end if else
    } // end of checkMove


    /**
     * @brief 
     * This function checks to see if the board is full
     * It does this by looping through and if it sees that no values
     * are equal to a '.', or a blank space, then it knows it is full
     * This is executed after a victory check to ensure that it only determines a tie
     * if the board is full AND there is no victory
     * 
     * @return true if the voard is full
     * @return false if the board is not full (by the presence
     * of a . character)
     */
    bool checkFull(){
        /* Create variable to return
           Assume it is full at start **/
        bool isFull = true;
        /// Utilize index and jindex for iterators
        for (int index = 0; index < 3; index ++){
            for (int jindex = 0; jindex < 3; jindex++){
                // Loop through the two-d array
                if(state[index][jindex] == '.'){
                    // If you find a '.', its not full, so change the bool
                    isFull = false;
                }
            } // end inner j for
        } // end outer i for     
        // Return the bool
        return isFull;     
    } // end checkFull

    /**
     * @brief This function handles the logic of determining if the game is over
     *  It does this by checking the following:
     * 1. That the space isn't empty (denoted by a '.')
     * 2. That there is a proper 3-consecutive sequence of the same character (that
     * is not a '.')
     * 
     * If the game is over, alert the players and terminate
     * Otherwise, continue
     * 
     * @param name Pass in the name of the Player who most recently played
     * so it can be determined how their play affected the game
     * 
     */
    int checkStatus(string name){
        // Create a bool to determine if the board is full
        bool isFull;
        // Determine if the board is full
        isFull = checkFull();

        /**
         * @brief 
         * The following sections check different winning conditions
         * Those conditions are noted in the comments at the end of each control block
         * The comments were left as doxygen comments to be seen in the documentation
         */
        if (state[0][0] != '.' && (state[0][0] == state[0][1] && state[0][1] == state[0][2])){
            cout << name << " WINS!" << endl;
            exit(0);
        } /// Straight across top row

        else if (state[1][0] != '.' && (state[1][0] == state[1][1] && state[1][1] == state[1][2])){
            cout << name << " WINS!" << endl;
            exit(0);
        } /// Straight across middle row

        else if (state[2][0] != '.' && (state[2][0] == state[2][1] && state[2][1] == state[2][2])){
            cout << name << " WINS!" << endl;
            exit(0);
        } /// Straight across bottom row

        else if (state[0][0] != '.' && (state[0][0] == state[1][0] && state[1][0] == state[2][0])){
            cout << name << " WINS!" << endl;
            exit(0);
        } /// Straight down first col

        else if (state[0][1] != '.' && (state[0][1] == state [1][1] && state[1][1] == state[2][1])){
            cout << name << " WINS!" << endl;
            exit(0);
        } /// Straight down second col

        else if (state[0][2] != '.' && (state[0][2] == state [1][2] && state[1][2] == state[2][2])){
            cout << name << " WINS!" << endl;
            exit(0);
        } /// Straight down third col

        else if (state[2][0] != '.' && (state[2][0] == state[1][1] && state[1][1] == state[0][2])){
            cout << name << " WINS!" << endl;
            exit(0);
        } /// Diagonal starting bottom left going up

        else if (state[0][0] != '.' && (state[0][0] == state[1][1] && state[1][1] == state[2][2])){
            cout << name << " WINS!" << endl;
            exit(0);
            /// Diagonal starting top left going down
        }
        /// At this point, nobody has won, so check if the board is full
        else if (isFull == true){
            /// If it is, alert a tie, and end
            cout << " TIE " << endl;
            exit(0);
        }
        /// otherwise, keep playing!
        else{
            /// nobody has won
            return 0;
        } /// end else

    } // end function checkStatus

    // Private member data
    private:
    /** Create the "grid", called the state, and initialize values to a '.'
    for better readability of the tic tac toe board **/
    char state[3][3] =  { 
                            {'.', '.', '.'},
                            {'.', '.', '.'},
                            {'.', '.', '.'}
                        }; // finished creating state

}; // end board class