#include "Board.h"
#include <iostream>

Board::Board() {
    // Initialize grid with zeros (empty cells)
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            grid[i][j] = 0;
        }
    }
}

void Board::displayBoard() const {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cout << grid[i][j] << " ";
            if ((j + 1) % 3 == 0 && j != 8) std::cout << "| ";
        }
        std::cout << std::endl;
        if ((i + 1) % 3 == 0 && i != 8) std::cout << "---------------------" << std::endl;
    }
}

bool Board::placeNumber(int row, int col, int num) {
    if (isValidMove(row, col, num)) {
        grid[row][col] = num;
        return true;
    }
    return false;
}

bool Board::isValidMove(int row, int col, int num) const {
    return checkRow(row, num) && checkCol(col, num) && checkSubGrid(row, col, num);
}

bool Board::checkRow(int row, int num) const {
    for (int col = 0; col < 9; col++) {
        if (grid[row][col] == num) return false;
    }
    return true;
}

bool Board::checkCol(int col, int num) const {
    for (int row = 0; row < 9; row++) {
        if (grid[row][col] == num) return false;
    }
    return true;
}

bool Board::checkSubGrid(int row, int col, int num) const {
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[startRow + 1][startCol + j] == num) return false;
        }        
    }
    return true;
}

bool Board::isSolved() const {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == 0) return false;
        }
    }
    return true;
}
