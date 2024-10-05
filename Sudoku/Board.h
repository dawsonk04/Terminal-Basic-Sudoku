// declration of a class that represents the board

#ifndef BOARD_H
#define BOARD_H

class Board {
public:
	Board();
	void displayBoard() const;
	bool placeNumber(int row, int col, int num);
	bool isSolved() const;
	bool isValidMove(int row, int col, int num) const;


private:
	int grid[9][9];
	bool checkRow(int row, int num) const;
	bool checkCol(int col, int num) const;
	bool checkSubGrid(int row, int col, int num) const;
};

#endif