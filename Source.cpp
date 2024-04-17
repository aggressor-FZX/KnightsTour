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

// FUNCTION PROTOTYPES
bool moveKnight(int row, int col, int movNum);
void printBoard(const vector< vector<int>> board);
long int scaleCount(int x, int y);

// GLOBALS
int ROWS = 8; //y-value
int COLS = 8;//x-value

int START_X = 3;
int START_Y = 3;

long long int COUNT = 0;
long long int RESET = 0;
long long int SHOW = scaleCount(ROWS, COLS);//Scale Factor : (x*1.5)^(y)
// Global 2D Vector for board 
vector<vector<int>> boardVec(ROWS, vector<int>(COLS, -1));// initilize with negative one



//made the board size changeble for non-standard boards
int main()
{

	//prepare vector initilized with ones

	bool done = moveKnight(START_X, START_Y, 0);
	cout << "total tries: " << COUNT << endl;
	cout << "total bad moves: " << RESET << endl;
	printBoard(boardVec);
	return 0;
}

bool moveKnight(int x, int y, int movNum)
{

	bool done = false;

	if (COUNT%SHOW ==0)
	{
		printBoard(boardVec);
		cout << "Count " << COUNT << endl;
		cout << "move num" << movNum << endl;
	}

	//all done condition

	COUNT++;//count tries

	//	Is on the board? and haven't visited check
	if ((x >= 0 && y >= 0) && ((x < ROWS) && (y < COLS)) && (boardVec[x][y] == -1))
	{
		//meets all conditions..
		boardVec[x][y] = movNum;// Then we record it

		// if we put down last move we return
		if (movNum == (COLS * ROWS - 1))
		{
			return true;
		}	
	}			
	else
	{ 
		//Can't move here return false
		return false; 
	}

	// wasn't last move, go on to look for the next move
	if (
		(!moveKnight(x + 1, y + 2, movNum + 1))&&//1
		(!moveKnight(x + 2, y + 1, movNum + 1))&&//2
		(!moveKnight(x + 2, y - 1, movNum + 1))&&//3
		(!moveKnight(x + 1, y - 2, movNum + 1))&&//4
		(!moveKnight(x - 1, y - 2, movNum + 1))&&//5
		(!moveKnight(x - 2, y - 1, movNum + 1))&&//6
		(!moveKnight(x - 2, y + 1, movNum + 1))&&//7
		(!moveKnight(x - 1, y + 2, movNum + 1)) // 8
		)
	{
		//Bad move result 
		boardVec[x][y] = -1;//reset the square
		RESET++;//bad move counter
		return false;

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

//Scale Factor : (x*1.5)^(y)
long int scaleCount(int x, int y)
{
	long int expo = 1;

	for (int i = 0; i < y; i++)
	{
	 expo = expo*(x)*1.5;
	}
	cout << "value is " << expo << endl;

	return expo;
}


/*  OUTPUT
* 
* total tries: 44822830627
* total bad moves: 5602853798
*  51  48  53  46  23   2  19  10
*  54  45  50  35  20  11  22   3
*  49  52  47  24   1  18   9  12
*  44  55  34  41  36  21   4  17
*  59  40  43   0  25   8  13  28
*  56  33  58  37  42  27  16   5
*  39  60  31  26   7  62  29  14
*  32  57  38  61  30  15   6  63
*
*
* C:\Users\jeffd\source\repos\KnightsTour\x64\Debug\KnightsTour.exe (process 17504) exited with code 0.
*/
