// 1101_FinalProject.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>

// we can use namespace just for now and add the "std::" to all the i/o commands after
using namespace std;

int main() 
{
    int number = 0;
    number = 9 / 5;
    cout << number;

}


// Global variable
const int MAX_SIZE = 100;

// Function Prototypes
void numberBoard(char arr[][3]);  // This function assigns the array a number for every place on the board 
void playerAnnouncement(int moves, string& player1, string& player2);  // Greeting at the begining of the game, announces player1's turn and player2's turn 
void playerMove(int& row, int& column);
void placeCheck(int row, int column);  // This function checks to see if player input is between (1-9) and to see if there is a piece already on the spot 
void winnerCheck(char arr[][3], int& counter, bool winner);


int main()
{
    char gameBoard[3][3];
    int  i = 0, counter = 1, row, column;
    string player1, player2;
    bool winner = false, turn = false;
    
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
                    gameBoard[row][column] == 'X';
                    turn = true;
                }
            } while (turn != true);
            turn = false;
        }

        if (counter % 2 == 0) 
        {
            do 
            {
                playerMove(row, column);
                placeCheck(row, column);
                if (gameBoard[row][column] == ' ')
                {
                    gameBoard[row][column] == 'O';
                    turn = true;
                }
            } while (turn != true);
            turn = false;
        }
        winnerCheck(gameBoard, counter, winner);
        counter++;


    } while (winner != true);

   
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
    arr[1][1] = ' ';
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
        cout << "\nThank you, lets get started.\n";
    }

    if (moves % 2 == 1) 
    {
        cout << player1 << "'s move.\n";
    }
    if (moves % 2 == 0) 
    {
        cout << player2 << "'s move.\n";
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


void winnerCheck(char arr[][3], int& counter, bool winner) 
{
    if (arr[0][0] && arr[0][1] && arr[0][2] == 'X' || 'O')
    {
        winner = true;
    }
    else if (arr[1][0] && arr[1][1] && arr[1][2] == 'X' || 'O')
    {
        winner = true;
    }
    else if (arr[2][0] && arr[2][1] && arr[2][2] == 'X' || 'O')
    {
        winner = true;
    }
    else if (arr[0][0] && arr[1][0] && arr[2][0] == 'X' || 'O')
    {
        winner = true;
    }
    else if (arr[0][1] && arr[1][1] && arr[2][1] == 'X' || 'O')
    {
        winner = true;
    }
    else if (arr[0][2] && arr[1][2] && arr[2][2] == 'X' || 'O')
    {
        winner = true;
    }
    else if (arr[0][0] && arr[1][1] && arr[2][2] == 'X' || 'O')
    {
        winner = true;
    }
    else if (arr[0][2] && arr[1][1] && arr[2][0] == 'X' || 'O')
    {
        winner = true;
    }
    else
        winner = false;

    if(counter = 9 && winner = false)
    {
        cout << "Game Tied!";
    }

}


