// 1101_FinalProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Update check

#include <iostream>

// we can use namespace just for now and add the "std::" to all the i/o commands after
using namespace std;

// Global variables
const int MAX_SIZE = 100;

// Function Prototypes
void numberBoard(int arr[][3]);  // This function assigns the array a number for every place on the board 
void placeCheck(int playerMove, int moves);  // This function checks to see if the players move is between (1-9) and checks to see if there is a piece already on a spot 


int main()
{
    int arraylist[3][3], playerMove = 0, i = 0, counter = 0;
   
    numberBoard(arraylist);
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


void placeCheck(int playerMove, int moves) 
{
    int i = 0, count = 0, arr[MAX_SIZE];
    arr[moves] = playerMove;
    
    if (playerMove < 1 || playerMove > 9)
    {
        cout << "The spot you choose does not exist\n";
    }

    for (i, i < MAX_SIZE; i++;) 
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