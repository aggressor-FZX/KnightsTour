// Assignment: Kights Tour
// Author: Jeff Calderon
// CS 131 Section: 33616
// Discription:
// shows the moves a knight must make to complete
// a tour of a chess board without landing on
// the same square twice. A tour means it lands
// on every square once on the board once. 
// Result is a grid with knight moves in numerical order
// This program will solve any size board (eventually)
// Just change the Global ROWS and COLS value

#include <iostream>
#include <vector>
#include <iomanip> 

using namespace std;


int ROWS = 5; //y-value
int COLS = 5;//x-value

int START_X = 0;
int START_Y = 0;

long long int COUNT = 0;
long long int RESET = 0;

// Global 2D Vector for board 
vector<vector<int>> boardVec(ROWS, vector<int>(COLS, -1));// initilize with negative one

// FUNCTION PROTOTYPES
bool moveKnight(int row, int col, int movNum);
void printBoard(const vector< vector<int>> board);

//made the board size changeble for non-standard boards
int main()
{

	//prepare vector initilized with ones
	int start_x = START_X;
	int start_y = START_Y;
	cout << " x " <<START_X  << "y " << START_Y << "\n";

	bool done = moveKnight(start_x, start_y, 0);
	cout << "total tries: " << COUNT << endl;
	cout << "total bad moves: " << RESET << endl;
	printBoard(boardVec);
	return 0;
}

bool moveKnight(int x, int y, int movNum)
{

	cout << " x " << x << "y " << y << "\n";
	if (COUNT % (COLS * ROWS)*10000000000 == 0)
	{
		printBoard(boardVec);
		cout << "Count " << COUNT << endl;
	}

	if (movNum == (COLS * ROWS - 1))
	{
		return true;
	}	

	COUNT++;//count tries
	cout << " x " << x << "y " << y << "\n";
	//	Is on the board? and haven't visited check
	if ((x >= 0 && y >= 0) && ((x < ROWS) && (y < COLS)) && (boardVec[x][y] == -1))
	{
		//meets all conditions..
		cout << "meets all conditions..\n";
		boardVec[x][y] = movNum;// Then we record it

	}			
	else
	{ 
		//not on board or 
		return false; 
	}
	cout << " x " << x << "y " << y << "\n";
	//go on to look for the next move
	if (!moveKnight(x + 1, y + 2, movNum + 1))//1
	{
		if (!moveKnight(x + 2, y + 1, movNum + 1))// 2
		{
			if (!moveKnight(x + 2, y - 1, movNum + 1))// 3
			{
				if (!moveKnight(x + 1, y - 2, movNum + 1)) // 4
				{
					if (!moveKnight(x - 1, y - 2, movNum + 1)) // 5
					{
						if (!moveKnight(x - 2, y - 1, movNum + 1)) // 6
						{
							if (!moveKnight(x - 2, y + 1, movNum + 1)) // 7
							{
								if (!moveKnight(x - 1, y + 2, movNum + 1)) // 8
								{
									boardVec[x][y] = -1;//reset the square
									RESET++;//bad move counter
									return false;

								}
							}
						}
					}
				}
			}
		}
	}
}

	
void printBoard(const vector< vector<int>> board)
{
	for( int y = ROWS-1; y >= 0; y--)
	{
		for (int x = 0; x < COLS; x++)
		{
			cout << setw(4) << board[x][y];
		}
		cout << endl;
	}
	cout << endl;

}
