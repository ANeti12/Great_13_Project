/* ----------------------------------------------------------------------
    Program 2: Great 13
        Peg puzzle. Jump pegs to try and leave only a single peg.

    Course: CS 141, Fall 2021
    System: Mac using CLion
    Author: Abhi Neti
   ----------------------------------------------------------------------
*/
#include <iostream>
#include <cctype>   // for toupper()
#include <cmath> // for fabs()
using namespace std;

// Initializing global variables pA - pM to display pieces on board
char pA = '#', pB = '#', pC = '#', pD = '#', pE = '#', pF = '#', pH = '#', pI = '#', pJ = '#', pK = '#', pL = '#', pM = '#';
char pG = '.';

// Display the game instructions.
void displayInstructions()
{
    cout << "Class: CS 141             \n"
    << "Program: #2 Great 13      \n"
    << "  \n"
    << "Make a series of jumps until there is a single piece left in the   \n"
    << "middle. On each move you must jump an adjacent piece into an empty \n"
    << "square, jumping horizontally, vertically, or diagonally.           \n"
    << "Input of 'R' resets the board back to the beginning, and input of  \n"
    << "'X' exits the game.'   \n"
    << endl;
} //end displayInstructions()

// Display the board, using the global variables pA - pM
void displayBoard()
{
    cout <<"\n "
    <<                 "    Board   " <<            " Position \n"
    <<"       "             << pA <<             "          A    \n"
    <<"     " <<      pB<<" "<<pC<<" "<<pD<<       "      B C D  \n"
    <<"   "<<pE<<" "<<pF<<" "<<pG<<" "<<pH<<" "<<pI<<"  E F G H I\n"
    <<"     " <<      pJ<<" "<<pK<<" "<<pL<<       "      J K L  \n"
    <<"       "             << pM <<             "          M    \n"
    << endl;
} //end displayBoard()

int setPosFromInput(char& userInput) //sets position given input
{
    int position = 0;
    if (userInput == 'A')
    {
        position = 1;
    }
    else if (userInput == 'B')
    {
        position = 2;
    }
    else if (userInput == 'C')
    {
        position = 3;
    }
    else if (userInput == 'D')
    {
        position = 4;
    }
    else if (userInput == 'E')
    {
        position = 5;
    }
    else if (userInput == 'F')
    {
        position = 6;
    }
    else if (userInput == 'G')
    {
        position = 7;
    }
    else if (userInput == 'H')
    {
        position = 8;
    }
    else if (userInput == 'I')
    {
        position = 9;
    }
    else if (userInput == 'J')
    {
        position = 10;
    }
    else if (userInput == 'K')
    {
        position = 11;
    }
    else if (userInput == 'L')
    {
        position = 12;
    }
    else if (userInput == 'M')
    {
        position = 13;
    }
    return position;
}//end of setMoveFromPos

char getBoardValue(int position)//relates position to character variable on board
{
    char boardPiece = ' ';
    if (position == 1) //
    {
        boardPiece = pA;
    }
    else if (position == 2)
    {
        boardPiece = pB;
    }
    else if (position == 3)
    {
        boardPiece = pC;
    }
    else if (position == 4)
    {
        boardPiece = pD;
    }
    else if (position == 5)
    {
        boardPiece = pE;
    }
    else if (position == 6)
    {
        boardPiece = pF;
    }
    else if (position == 7)
    {
        boardPiece = pG;
    }
    else if (position == 8)
    {
        boardPiece = pH;
    }
    else if (position == 9)
    {
        boardPiece = pI;
    }
    else if (position == 10)
    {
        boardPiece = pJ;
    }
    else if (position == 11)
    {
        boardPiece = pK;
    }
    else if (position == 12)
    {
        boardPiece = pL;
    }
    else if (position == 13)
    {
        boardPiece = pM;
    }
    return boardPiece;
}//end of getBoardValueMovingFrom

int setPosRow(int& position)//sets the row number given position
{
    int row;
    if(position == 1)
    {
        row = 1;
    }
    if(position >= 2 && position <= 4)
    {
        row=2;
    }
    if(position >= 5 && position <= 9)
    {
        row=3;
    }
    if(position >= 10 && position <= 12)
    {
        row=4;
    }
    if(position == 13)
    {
        row = 5;
    }
    return row;
}//end of setPosRow

int setPosCol(int& position)//sets the column number given position
{
    int col;
    if (position == 5)
    {
        col = 1;
    }
    if (position == 2 || position == 6 || position == 10)
    {
        col = 2;
    }
    if (position == 1 || position == 3 || position == 7 || position == 11 || position == 13)
    {
        col = 3;
    }
    if (position == 4 || position == 8 || position == 12)
    {
        col = 4;
    }
    if (position == 9)
    {
        col = 5;
    }
    return col;
}//end of setPosCol

bool checkAdjacent(int& row1, int& col1, int& row2, int& col2, int& row3, int& col3)//checks if three inputs are adjacent, given (row1, col1) is the position of an input
{
    if(((row1 != row2) && (row2 == row3)) || ((row1!= row2) && (row1 == row3))
    || ((row1 == row2) && (row2 != row3)) || ((col2 == col3) && (col2 != col1))
    || ((col1 == col2) && (col2 != col3)))
    {
        cout<< endl << "   *** Pieces must be adjacent. Please retry"<< endl << endl;
        return false;
    }
    if ((!((fabs(row2 - row3) <= 1) && (fabs(row1 - row2) <= 1) && (fabs(col1 - col2) <= 1) && (fabs(col3 - col2) <= 1))))
    {
        cout<< endl << "   *** Pieces must be adjacent. Please retry"<< endl << endl;
        return false;
    }
    else
    {
        return true;
    }
}//end checkAdjacent

bool checkOtherErrors(char& moveFrom, char& moveJump, char& moveTo, bool& error)//checks for other errors
{
    error = false;
    if (moveFrom == '.')
    {
        cout << endl << "   *** Source must have a piece. Please retry" << endl << endl;
        error = true;
    }
    else if (moveJump == '.')
    {
        cout << endl << "   *** Must jump a piece. Please retry" << endl << endl;
        error = true;
    }
    else if (moveTo == '#')
    {
        cout << endl << "   *** Destination must be blank. Retry" << endl << endl;
        error = true;
    }
    return error;
}//end of checkOtherErrors

void playGame(char& moveFrom, char& moveJump, char& moveTo, bool& error)//method to change the pieces
{
    char temp2 = moveTo; // temporary variable in order to change moveFrom and moveJump to moveTo
    moveTo = moveFrom;
    moveFrom = temp2;
    moveJump = temp2;
    error = false;
}//end of playGame

void setDisplayValues(char value, int position) //updates character variables on board
{
    if (position == 1)
    {
        pA = value;
    }
    else if (position == 2)
    {
        pB = value;
    }
    else if (position == 3)
    {
        pC = value;
    }
    else if (position == 4)
    {
        pD = value;
    }
    else if (position == 5)
    {
        pE = value;
    }
    else if (position == 6)
    {
        pF = value;
    }
    else if (position == 7)
    {
        pG = value;
    }
    else if (position == 8)
    {
        pH = value;
    }
    else if (position == 9)
    {
        pI = value;
    }
    else if (position == 10)
    {
        pJ = value;
    }
    else if (position == 11)
    {
        pK = value;
    }
    else if (position == 12)
    {
        pL = value;
    }
    else if (position == 13)
    {
        pM = value;
    }
}//end setDisplayValue

void resetBoard()
{
    pA = '#', pB = '#', pC = '#', pD = '#', pE = '#', pF = '#', pH = '#', pI = '#', pJ = '#', pK = '#', pL = '#', pM = '#';
    pG = '.';
    cout << endl << "   *** Restarting" << endl;
}

// Main section of the program, containing the game play loop
int moveNumber = 1;
int main()
{
    displayInstructions();
    // Set board values to the default starting position
    // Game play loop
    displayBoard();
    int numberOfPieces = 12;
    while(numberOfPieces > 1)
    {
        char moveFrom, moveJump, moveTo;
        cout << moveNumber << ". "
        << "Enter positions from, jump, and to (e.g. EFG): ";
        cin >> moveFrom; // Read just the first user input, handling inputs 'X' or 'R'
        moveFrom = toupper(moveFrom);  // Fold input into upper case to simplify later comparisons
        // If 'X' to exit was chosen, break out of game play loop
        if (moveFrom == 'X')
        {
            cout << "Exiting" << endl << endl << "Better luck next time." << endl;
            break;
        }
        // If 'R' to reset the board was chosen, reinitialize everything display the board, and continue back up to re-run the while(...) loop
        if (moveFrom == 'R')
        {
            resetBoard();
            displayBoard();
            moveNumber = 1;
            numberOfPieces = 12;
            continue;
        }
        // Additionally now also read the piece-to-jump and destination inputs.
        cin >> moveJump;
        moveJump = toupper(moveJump);
        cin >> moveTo;
        moveTo = toupper(moveTo);

        int moveFromInt = setPosFromInput(moveFrom); // sets positions given user input
        int moveJumpInt = setPosFromInput(moveJump);
        int moveToInt = setPosFromInput(moveTo);

        char moveFromPiece = getBoardValue(moveFromInt); // takes positions from above and assigns board value
        char moveJumpPiece = getBoardValue(moveJumpInt);
        char moveToPiece = getBoardValue(moveToInt);

        int row1 = setPosRow(moveFromInt); // determines rows and columns given position
        int col1 = setPosCol(moveFromInt);
        int row2 = setPosRow(moveJumpInt);
        int col2 = setPosCol(moveJumpInt);
        int row3 = setPosRow(moveToInt);
        int col3 = setPosCol(moveToInt);

        bool adj = checkAdjacent(row1, col1, row2, col2, row3, col3); // given rows and columns, determines if adjacent
        if (adj == false) // if not adjacent, prompts user to pick different pieces
        {
            continue;
        }
        bool var1 = false;
        bool other = checkOtherErrors(moveFromPiece, moveJumpPiece, moveToPiece, var1); // checks for other errors
        bool error = true;
        if (adj && !other)
        {
            playGame(moveFromPiece, moveJumpPiece, moveToPiece, error); // plays game if adjacent and no other errors
        }

        setDisplayValues(moveFromPiece, moveFromInt);
        setDisplayValues(moveJumpPiece, moveJumpInt);
        setDisplayValues(moveToPiece, moveToInt);

        if (!error) // occurs when no error occurs
        {
            moveNumber++;
            displayBoard();
            numberOfPieces--;
        }

        if(numberOfPieces == 1) // Check for win
        {
            cout << endl << "Congratulations, you did it!" << endl;
        }
    } //end while(numberOfPieces > 1)
    cout << "Done." << endl;
    return 0;
}//end main()