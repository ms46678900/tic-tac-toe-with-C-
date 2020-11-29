// A C++ Program to play tic-tac-toe

#include<bits/stdc++.h>
using namespace std;


#define SIDE 3 // Length of the board


// A function to show the current board status
void showBoard(char board[SIDE][SIDE])
{
    cout<<"\n\n";

    cout<<"\t\t\t "<< board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
    cout<<"\t\t\t--------------\n";
    cout<<"\t\t\t "<< board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
    cout<<"\t\t\t--------------\n";
    cout<<"\t\t\t "<< board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;

    return;
}

// A function to show the instructions
void showInstructions()
{

    cout<<"Choose a cell numbered from 1 to 9 as below and play\n\n";

    cout<<"\t\t\t  1 | 2  | 3  \n";
    cout<<"\t\t\t--------------\n";
    cout<<"\t\t\t  4 | 5  | 6  \n";
    cout<<"\t\t\t--------------\n";
    cout<<"\t\t\t  7 | 8  | 9  \n\n";

    cout<<"-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n";

    return;
}


// A function to initialise the game
void initialise(char board[][SIDE], int moves[])
{
    // Initiate the random number generator so that
    // the same configuration doesn't arises
    srand(time(NULL));

    // Initially the board is empty
    for (int i=0; i<SIDE; i++)
    {
        for (int j=0; j<SIDE; j++)
            board[i][j] = ' ';
    }

    // Fill the moves with numbers
    for (int i=0; i<SIDE*SIDE; i++)
        moves[i] = i;

    // randomise the moves
    random_shuffle(moves, moves + SIDE*SIDE);

    return;
}

// A function to declare the winner of the game
void declareWinner(string whoseTurn,string X_player,string O_player)
{
    if (whoseTurn == O_player)
        cout<<O_player<< " has won"<<endl;
    else
        cout<<X_player<< " has won"<<endl;
    return;
}

// A function that returns true if any of the row
// is crossed with the same player's move
bool rowCrossed(char board[][SIDE])
{
    for (int i=0; i<SIDE; i++)
    {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2] &&
            board[i][0] != ' ')
            return (true);
    }
    return(false);
}

// A function that returns true if any of the column
// is crossed with the same player's move
bool columnCrossed(char board[][SIDE])
{
    for (int i=0; i<SIDE; i++)
    {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i] &&
            board[0][i] != ' ')
            return (true);
    }
    return(false);
}

// A function that returns true if any of the diagonal
// is crossed with the same player's move
bool diagonalCrossed(char board[][SIDE])
{
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2] &&
        board[0][0] != ' ')
        return(true);

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0] &&
         board[0][2] != ' ')
        return(true);

    return(false);
}

// A function that returns true if the game is over
// else it returns a false
bool gameOver(char board[][SIDE])
{
    return(rowCrossed(board) || columnCrossed(board)
            || diagonalCrossed(board) );
}

// A function to play Tic-Tac-Toe
void playTicTacToe(string whoseTurn,string X_player,string O_player)
{
    // A 3*3 Tic-Tac-Toe board for playing
    char board[SIDE][SIDE];

    int moves[SIDE*SIDE]={0};

    // Initialise the game
    initialise(board, moves);

    // Show the instructions before playing
    showInstructions();

    int moveIndex = 0,x=0;

    // Keep playing till the game is over or it is a draw
    while (gameOver(board) == false )
    {
        if (whoseTurn == O_player)
        {
            cout<<"\t\t"<<O_player<<"'s Turn\n"<<endl;
            cout<<"\t\tEnter Cell Number:: "<<endl;
            cin>>moveIndex;
            if(moveIndex<1 && moveIndex>9)
            {
                cout<<"\t\tInvalid Move"<<endl;
                exit(1);
            }

            moves[x]=moveIndex;
            x++;


            if(moveIndex>=1 && moveIndex<=3)
                board[0][moveIndex-1]='O';
            if(moveIndex>3 && moveIndex<=6)
                board[1][moveIndex-4]='O';
            if(moveIndex>6 && moveIndex<=9)
                board[2][moveIndex-7]='O';


            cout<<"\n\t\t"<<O_player<<" has put a"<<" O"<<" in cell "<<  moveIndex<<endl;
            showBoard(board);

            whoseTurn = X_player;
        }

        else if (whoseTurn == X_player)
        {
            cout<<"\t\t"<<X_player<<"'s Turn\n"<<endl;
            cout<<"\t\tEnter Cell Number:: "<<endl;
            cin>>moveIndex;
            if(moveIndex<1 && moveIndex>9)
            {
                cout<<"\t\tInvalid Move"<<endl;
                exit(1);
            }

            moves[x]=moveIndex;
            x++;

            if(moveIndex>=1 && moveIndex<=3)
                board[0][moveIndex-1]='X';
            if(moveIndex>3 && moveIndex<=6)
                board[1][moveIndex-4]='X';
            if(moveIndex>6 && moveIndex<=9)
                board[2][moveIndex-7]='X';

            cout<<"\n\t\t"<<X_player<<" has put a"<<"  X"<<" in cell "<<  moveIndex<<endl;
            showBoard(board);

            whoseTurn = O_player;
        }
    }

    // If the game has drawn
    if (gameOver(board) == false )
        cout<<"It's a Tie"<<endl;
    else
    {
        // Toggling the user to declare the actual
        // winner
        if (whoseTurn == O_player)
            whoseTurn = X_player;
        else if (whoseTurn ==X_player)
            whoseTurn = O_player;

        // Declare the winner
        declareWinner(whoseTurn,X_player,O_player);
    }
    return;
}

// Driver program
int main()
{
    string X_player,O_player,first_move;
    cout<<"\t\t\t  Tic-Tac-Toe\n\n";
    cout<<"\tEnter X player Name:: ";
    getline(cin,X_player);

    cout<<"\tEnter O player Name:: ";
    getline(cin,O_player);

    cout<<"\n\tEnter Name of player who will play first:: "<<endl;
    cout<<"\n\t\tEnter "<<X_player<<" for X player"<<endl;
    cout<<"\t\tEnter "<<O_player<<" for O player"<<endl;
    getline(cin,first_move);
    if(first_move==O_player || first_move==X_player)
    {

        cout<<"\t\t\tGAME STARTED"<<endl;

    // Let us play the game with COMPUTER starting first
        playTicTacToe(first_move,X_player,O_player);
    }
    return (0);
}
