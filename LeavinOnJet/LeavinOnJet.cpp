/*
* File:LeavinOnJet
* Author: Seth Skinner
* Date: 4/10/2025
*
* Description: Simulates reserving seats on a plane with 50 seats(4 columns, 13 rows). Uses a 2 dimensional array for columns and rows.Displays layout of plane and available seats.
* When a seat is reserved an x replaces it. If a user reserves an unavailaBle seat, returns error message and prompts again. Takes seat as so: 12A, 3B, 5D, etc.
*/

#include<iostream>
#include<string>

using namespace std;

int const ROWS = 9;
int const COLUMNS = 13;

int findRowIndex(int thisRow);
int findSeatIndex(char thisSeat);
void displaySeatColumn(char seats[ROWS][COLUMNS]);
void reserveSeat(char seats[ROWS][COLUMNS], int row, int col);
char getSeatLetter(int rowIndex);

int main()
{
    // Seating Chart Array
    char seats[ROWS][COLUMNS] =
    {
        {'D','D','D','D','D','D','D','D','D','D','D','D','x'},
        {'C','C','C','C','C','C','C','C','C','C','C','C','x'},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ','1','1','1','1'},
        {'1','2','3','4','5','6','7','8','9','0','1','2','3'},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {'B','B','B','B','B','B','B','B','B','B','B','B','B'},
        {'A','A','A','A','A','A','A','A','A','A','A','A','A'}
    };

    // Pre-reserve 13C and 13D
    seats[1][12] = 'X'; // 13C
    seats[0][12] = 'X'; // 13D

}