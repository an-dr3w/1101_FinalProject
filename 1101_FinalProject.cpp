// 1101_FinalProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Update check

#include <iostream>

// we can use namespace just for now and add the "std::" to all the i/o commands after
using namespace std;

// Global variables
const int MAX_SIZE = 100;

// Function Prototypes
void numberBoard(int);  // This function assigns the array a number for every place on the board
void moveCheck(int);  // This function checks to see if the players move is between (1-9)
void placeCheck(int, int);

int main()
{
    int arraylist[3][3], playerMove = 0;
    numberBoard(arraylist);

    
}

void numberBoard(int arr[3][3]) 
{
    int i = 0, x = 0, y = 0;

    for (i , i < 9; i++;) 
    {
        if (x == 2) 
        {
            x = 0;
            y++;
        }
        arr[x][y] = i + 1;
        x++;
    }

}


void moveCheck(int playerMove) 
{
    if (playerMove < 1 || playerMove > 9)
    {
        cout << "The spot you choose does not exist\n";
    }
}


void placeCheck(int arr[], int playerMove) 
{
    int i = 0; 
    arr[MAX_SIZE];
    
    for (i, i < MAX_SIZE; i++;) 
    {
        if (playerMove < 1 || playerMove > 9) 
        {
            break;
        }
        else if (playerMove == arr[i]) 
        {
            cout << "This spot is already taken\n";
        }
    }
    i = 0;
}