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

    // Displays seating chart
    displaySeatColumn(seats);

    string seatInput;

    while (true)
    {
        cout << "\nPlease Enter Your Desired Seat (e.g., 12A, 3B) or type 'exit' to quit: ";
        cin >> seatInput;

        if (seatInput == "exit")
        {
            cout << "Exiting the program.\n";
            break;
        }

        if (seatInput.length() >= 2)
        {
            string rowStr = seatInput.substr(0, seatInput.length() - 1);
            char seatChar = toupper(seatInput.back()); // Support lowercase too

            int row = stoi(rowStr);

            if (row < 1 || row > 13 || seatChar < 'A' || seatChar > 'D')
            {
                cout << "Invalid seat input. Please try again.\n";
                continue;
            }

            int rowIndex = findRowIndex(row);
            int seatIndex = findSeatIndex(seatChar);

            if (seatIndex == -1)
            {
                cout << "Invalid seat letter.\n";
                continue;
            }

            reserveSeat(seats, seatIndex, rowIndex);
            displaySeatColumn(seats);
        }
        else
        {
            cout << "Invalid input. Please try again.\n";
        }
    }

    return 0;
}

void displaySeatColumn(char seats[ROWS][COLUMNS])
{
    cout << "\n";
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            cout << seats[i][j] << ' ';
        }
        cout << '\n';
    }
}

int findRowIndex(int thisRow)
{
    return thisRow - 1; // Convert from 1-based index to 0-based index
}

int findSeatIndex(char thisSeat)
{
    if (thisSeat == 'A' || thisSeat == 'B')
    {
        return 8 - (thisSeat - 'A');
    }

    if (thisSeat == 'C' || thisSeat == 'D')
    {
        return 'D' - thisSeat;
    }

    return -1; // Invalid seat
}

void reserveSeat(char seats[ROWS][COLUMNS], int row, int col)
{
    if (seats[row][col] != 'X')  // Check if seat is available
    {
        seats[row][col] = 'X'; // Mark seat as reserved
        cout << "Seat " << col + 1 << getSeatLetter(row) << " reserved successfully.\n";
    }
    else
    {
        cout << "Error: Seat " << row + 1 << (char)('A' + col) << " is already reserved.\n";
    }
}

char getSeatLetter(int rowIndex) {
    if (rowIndex == 8) return 'A';
    if (rowIndex == 7) return 'B';
    if (rowIndex == 1) return 'C';
    if (rowIndex == 0) return 'D';
}