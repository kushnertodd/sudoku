/*
 * sudoku.h
 *
 *  Created on: Feb 24, 2016
 *      Author: Todd
 */

#ifndef SUDOKU_H_
#define SUDOKU_H_

#include "common.h"
#include "board.h"
#include "cell.h"
#include "row.h"
#include "sudokucallback.h"
#include "sudokuinit.h"

using namespace std;

class Sudoku {
private:
    SudokuCallback& sudokuCallback;
    SudokuInit sudokuInit;

    //BoardPQ pq(PQ_ORDER_ASCENDING);
    BoardPQ pq;
public:
    Sudoku();
    Sudoku(SudokuCallback& sudokuCallback);

    void init(int argc, char **argv);
    void process();
};

#endif /* SUDOKU_H_ */

