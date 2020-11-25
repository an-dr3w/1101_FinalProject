// 1101_FinalProject.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>

// we can use namespace just for now and add the "std::" to all the i/o commands after
using namespace std;


// Function Prototypes
void numberBoard(char arr[][3]);  // This function assigns the array a number for every place on the board 
void playerAnnouncement(int moves, string& player1, string& player2);  // Greeting at the begining of the game, announces player1's turn and player2's turn 
void playerMove(int& row, int& column);
void placeCheck(int row, int column);  // This function checks to see if player input is between (1-9) and to see if there is a piece already on the spot 
int winnerCheck(char arr[][3], int counter, string player1, string player2);


int main()
{
    char gameBoard[3][3];
    int  winner = 0, counter = 1, row, column;
    string player1, player2;
    bool turn = 0;
    
    // Called function to number the game board 
    numberBoard(gameBoard);
   
    do {
      
        playerAnnouncement(counter, player1, player2);
        
        cout << gameBoard[0][0] << " | " << gameBoard[0][1] << " | " << gameBoard[0][2] << endl;
        cout << "__________" << endl;
        cout << gameBoard[1][0] << " | " << gameBoard[1][1] << " | " << gameBoard[1][2] << endl;
        cout << "__________" << endl;
        cout << gameBoard[2][0] << " | " << gameBoard[2][1] << " | " << gameBoard[2][2] << endl;
        
        if (counter % 2 == 1)
        {
            do 
            {
                playerMove(row, column);
                placeCheck(row, column);
                if (gameBoard[row][column] == ' ')
                {
                    gameBoard[row][column] = 'X';
                    turn = 1;
                }
            } while (turn == 0);
            turn = 0;
        }

        if (counter % 2 == 0) 
        {
            do 
            {
                playerMove(row, column);
                placeCheck(row, column);
                if (gameBoard[row][column] == ' ')
                {
                    gameBoard[row][column] = 'O';
                    turn = 1;
                }
            } while (turn == 0);
            turn = 0;
        }
        system("cls");
        winner = winnerCheck(gameBoard, counter, player1, player2);
        counter++;

    } while (winner == 0);

    
}


void numberBoard(char arr[][3]) 
{
    arr[0][0] = ' ';
    arr[0][1] = ' ';
    arr[0][2] = ' ';
    arr[1][0] = ' ';
    arr[1][1] = ' ';
    arr[1][2] = ' ';
    arr[2][0] = ' ';
    arr[2][1] = ' ';
    arr[2][2] = ' ';
}


void playerAnnouncement(int moves, string& player1, string& player2) 
{
    if (moves == 1) 
    {
        cout << "Welcome, to tic-tac-toe!\n" << "Player1 enter your name: ";
        cin >> player1;
        cout << "\nPlayer2 enter your name: ";
        cin >> player2;
        cout << "\nThank you, lets get started.\n\n";
    }

    if (moves < 10) 
    {
        if (moves % 2 == 1)
        {
            cout << player1 << "'s move.\n" << endl;
        }
        if (moves % 2 == 0)
        {
            cout << player2 << "'s move.\n" << endl;
        }
    }
}


void playerMove(int& row, int& column)
{
    cout << "Pick a row between [0-2]: ";
    cin >> row;
    cout << "\nPick a column between [0-2]: ";
    cin >> column;
    cout << endl;
}


void placeCheck(int row, int column) 
{
    // checking if player input is within the allowed board spaces 
    if (row < 0 && row > 2 || column < 0 && column > 2)
    {
        cout << "The spot you choose does not exist\n";
    }
}


int winnerCheck(char arr[][3], int counter, string player1, string player2) 
{
    int winner = 0;

    // Player1 winning argument 
    if (arr[0][0] == arr[0][1] && arr[0][0] == arr[0][2])
    {
        if (arr[0][0] == 'X')
        {
            winner = 1;
        }
        else if (arr[0][0] == 'O') 
        {
            winner = 2;
        }
    }
    
    if (arr[1][0] == arr[1][1] && arr[1][0] == arr[1][2])
    {
        if (arr[1][0] == 'X')
        {
            winner = 1;
        }
        else if (arr[1][0] == 'O')
        {
            winner = 2;
        }
    }
    
    if (arr[2][0] == arr[2][1] && arr[2][0] == arr[2][2])
    {
        if (arr[2][0] == 'X')
        {
            winner = 1;
        }
        else if (arr[2][0] == 'O')
        {
            winner = 2;
        }
    }
    
    if (arr[0][0] == arr[1][0] && arr[0][0] == arr[2][0])
    {
        if (arr[0][0] == 'X')
        {
            winner = 1;
        }
        else if (arr[0][0] == 'O')
        {
            winner = 2;
        }
    }
    
    if (arr[0][1] == arr[1][1] && arr[0][1] == arr[2][1])
    {
        if (arr[0][1] == 'X')
        {
            winner = 1;
        }
        else if (arr[0][1] == 'O')
        {
            winner = 2;
        }
    }
    
    if (arr[0][2] == arr[1][2] && arr[0][2] == arr[2][2])
    {
        if (arr[0][2] == 'X')
        {
            winner = 1;
        }
        else if (arr[0][2] == 'O')
        {
            winner = 2;
        }
    }
    
    if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2])
    {
        if (arr[0][0] == 'X')
        {
            winner = 1;
        }
        else if (arr[0][0] == 'O')
        {
            winner = 2;
        }
    }
    
    if (arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0])
    {
        if (arr[0][2] == 'X')
        {
            winner = 1;
        }
        else if (arr[0][2] == 'O')
        {
            winner = 2;
        }
    }

    cout << endl << winner << endl;
   
    // Tied game argument and picking a winner 
    if(counter == 9)
    {
        if (winner == 0) 
        {
            cout << "Game Tied!" << endl 
                 << arr[0][0] << " | " << arr[0][1] << " | " << arr[0][2] << endl;
            cout << "__________" << endl;
            cout << arr[1][0] << " | " << arr[1][1] << " | " << arr[1][2] << endl;
            cout << "__________" << endl;
            cout << arr[2][0] << " | " << arr[2][1] << " | " << arr[2][2] << endl;
        }
    }
    
    if (winner == 1) 
    {
        cout << player1 << " WON!" << endl
             << arr[0][0] << " | " << arr[0][1] << " | " << arr[0][2] << endl;
        cout << "__________" << endl;
        cout << arr[1][0] << " | " << arr[1][1] << " | " << arr[1][2] << endl;
        cout << "__________" << endl;
        cout << arr[2][0] << " | " << arr[2][1] << " | " << arr[2][2] << endl;
    }

    if (winner == 2) 
    {
        cout << player2 << " WON!" << endl
             << arr[0][0] << " | " << arr[0][1] << " | " << arr[0][2] << endl;
        cout << "__________" << endl;
        cout << arr[1][0] << " | " << arr[1][1] << " | " << arr[1][2] << endl;
        cout << "__________" << endl;
        cout << arr[2][0] << " | " << arr[2][1] << " | " << arr[2][2] << endl;
    }

    return winner;
}









/*
if (arr[0][0] == 'X' && arr[0][1] == 'X' && arr[0][2] == 'X')
{
    winner == true;
}
else if (arr[1][0] == 'X' && arr[1][1] == 'X' && arr[1][2] == 'X')
{
    winner == true;
}
else if (arr[2][0] == 'X' && arr[2][1] == 'X' && arr[2][2] == 'X')
{
    winner == true;
}
else if (arr[0][0] == 'X' && arr[1][0] == 'X' && arr[2][0] == 'X')
{
    winner == true;
}
else if (arr[0][1] == 'X' && arr[1][1] == 'X' && arr[2][1] == 'X')
{
    winner == true;
}
else if (arr[0][2] == 'X' && arr[1][2] == 'X' && arr[2][2] == 'X')
{
    winner == true;
}
else if (arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X')
{
    winner == true;
}
else if (arr[0][2] == 'X' && arr[1][1] == 'X' && arr[2][0] == 'X')
{
    winner == true;
}
else
winner == false;

// Player2 winning argument 
if (arr[0][0] == 'O' && arr[0][1] == 'O' && arr[0][2] == 'O')
{
    winner == true;
}
else if (arr[1][0] == 'O' && arr[1][1] == 'O' && arr[1][2] == 'O')
{
    winner == true;
}
else if (arr[2][0] == 'O' && arr[2][1] == 'O' && arr[2][2] == 'O')
{
    winner == true;
}
else if (arr[0][0] == 'O' && arr[1][0] == 'O' && arr[2][0] == 'O')
{
    winner == true;
}
else if (arr[0][1] == 'O' && arr[1][1] == 'O' && arr[2][1] == 'O')
{
    winner == true;
}
else if (arr[0][2] == 'O' && arr[1][2] == 'O' && arr[2][2] == 'O')
{
    winner == true;
}
else if (arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] == 'O')
{
    winner == true;
}
else if (arr[0][2] == 'O' && arr[1][1] == 'O' && arr[2][0] == 'O')
{
    winner == true;
}
else
winner == false;

*/

/*
if (counter == 9)
{
    if (winner == false)
    {
        cout << "Game Tied!" << endl
            << gameBoard[0][0] << " | " << gameBoard[0][1] << " | " << gameBoard[0][2] << endl;
        cout << "__________" << endl;
        cout << gameBoard[1][0] << " | " << gameBoard[1][1] << " | " << gameBoard[1][2] << endl;
        cout << "__________" << endl;
        cout << gameBoard[2][0] << " | " << gameBoard[2][1] << " | " << gameBoard[2][2] << endl;
    }
}

if (winner == true)
{
    if (counter % 2 == 1)
    {
        cout << player1 << " WON!" << endl
            << gameBoard[0][0] << " | " << gameBoard[0][1] << " | " << gameBoard[0][2] << endl;
        cout << "__________" << endl;
        cout << gameBoard[1][0] << " | " << gameBoard[1][1] << " | " << gameBoard[1][2] << endl;
        cout << "__________" << endl;
        cout << gameBoard[2][0] << " | " << gameBoard[2][1] << " | " << gameBoard[2][2] << endl;
    }
    if (counter % 2 == 0)
    {
        cout << player2 << " WON!" << endl
            << gameBoard[0][0] << " | " << gameBoard[0][1] << " | " << gameBoard[0][2] << endl;
        cout << "__________" << endl;
        cout << gameBoard[1][0] << " | " << gameBoard[1][1] << " | " << gameBoard[1][2] << endl;
        cout << "__________" << endl;
        cout << gameBoard[2][0] << " | " << gameBoard[2][1] << " | " << gameBoard[2][2] << endl;
    }
}

*/