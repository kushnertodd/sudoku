/*
 * main.cpp
 *
 *  Created on: Feb 3, 2017
 *      Author: kushn_du3a95r
 */
//============================================================================
// Name        : sudoku.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "sudoku.h"
#include "cell.h"
#include "row.h"
#include "sudokuinit.h"

int main(int argc, char **argv) {
    SudokuCallback sudokuCallback;
    Sudoku sudoku(sudokuCallback);
    if (SudokuInit::debugBoard())
        cout << "main: init" << endl;
    sudoku.init(argc, argv);
    /*
     * algorithm:
     * - take the starting board
     * - pick the empty cell with the fewest possible values -- many ties
     * - for its row, column, and box, add the total of filled cells
     *   to break the ties
     * - for each possibility of the empty cell, create a new board
     *   with that value filled in, and put it in a queue ordered by
     *   the total number of cells filled in
     * - take the next board off the queue, and process as above if
     *   the board is not complete.
     */
    if (SudokuInit::debugBoard())
        cout << "main: process" << endl;
    sudoku.process();
    return 0;
}

