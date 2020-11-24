// 1101_FinalProject.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

// we can use namespace just for now and add the "std::" to all the i/o commands after
using namespace std;

// Global variable
const int MAX_SIZE = 100;

// Function Prototypes
void numberBoard(int arr[][3]);  // This function assigns the array a number for every place on the board 
void playerAnnouncement(int moves, string& player1, string& player2);  // Greeting at the begining of the game, announces player1's turn and player2's turn 
void placeCheck(int playerMove, int moves);  // This function checks to see if player input is between (1-9) and to see if there is a piece already on the spot 


int main()
{
    int gameBoard[3][3], playerMove = 0, i = 0, counter = 0;
    string player1, player2;
    
    // Called function to number the game board 
    numberBoard(gameBoard);

    ++counter;
    playerAnnouncement(counter, player1, player2);
    cin >> playerMove;
    placeCheck(playerMove, counter);
    

   
}


void numberBoard(int arr[][3]) 
{
    arr[0][0] = 1;
    arr[0][1] = 2;
    arr[0][2] = 3;
    arr[1][0] = 4;
    arr[1][1] = 5;
    arr[1][2] = 6;
    arr[2][0] = 7;
    arr[1][1] = 8;
    arr[2][2] = 9;
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
        cout << endl << player1 << "'s move: ";
    }
    if (moves % 2 == 0) 
    {
        cout << endl << player2 << "'s move: ";
    }

}


void placeCheck(int playerMove, int moves) 
{
    int i = 0, count = 0, arr[MAX_SIZE];
    arr[moves] = playerMove;

    // checking if player input is within the allowed interval of [1-9] 
    if (playerMove < 1 || playerMove > 9)
    {
        cout << "The spot you choose does not exist\n";
    }

    // going through the list of previous moves to determine if the spot is already taken 
    for (i, i < moves; i++;) 
    {
        if (playerMove == arr[i]) 
        {
            cout << "This spot is already taken\n";
            break;
        }
    }
    i = 0;
    
}


// Function assigning a number to each place in the array

/* int i = 0, x = 0, y = 0;

   for (i , i < 9; i++;)
   {
       if (y == 2)
       {
           y = 0;
           x++;
       }
       arr[x][y] = i + 1;
       y++;
   }*/
