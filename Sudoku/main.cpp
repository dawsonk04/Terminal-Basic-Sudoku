#include <iostream>
#include "Board.h"

int main() {
    Board sudokuBoard;

    int row, col, num;
    char playAgain;

    std::cout << "Welcome to Sudoku!" << std::endl;

    do {
        sudokuBoard.displayBoard();

        std::cout << "Enter row (0-8), column (0-8), and number (1-9) to place: ";
        std::cin >> row >> col >> num;

        if (sudokuBoard.placeNumber(row, col, num)) {
            std::cout << "Number placed successfully!" << std::endl;
        }
        else {
            std::cout << "Invalid move, try again." << std::endl;
        }

        if (sudokuBoard.isSolved()) {
            std::cout << "Congratulations! You've solved the Sudoku puzzle!" << std::endl;
            break;
        }

        std::cout << "Do you want to continue? (y/n): ";
        std::cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
