//============================================================================
// Name        : sudoku.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "sudoku.h"
#include "sudokucallback.h"

void SudokuCallback::cellChanged(Cell& oldCell, Cell& newCell) {
    cout << "SudokuCallback::cellChanged:" << endl << "    oldCell: " << oldCell.to_string()
            << endl << "    newCell: " << newCell.to_string() << endl;
}
void SudokuCallback::boardCompleted(Board& board) {
    cout << "SudokuCallback::boardCompleted:" << endl;
    board.print("completed");
}
