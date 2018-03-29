/*
 * sudokucallback.h
 *
 *  Created on: Feb 24, 2016
 *      Author: Todd
 */

#ifndef SUDOKUCALLBACK_H_
#define SUDOKUCALLBACK_H_

#include "board.h"
#include "cell.h"

class SudokuCallback {
public:
    void cellChanged(Cell& oldCell, Cell& newCell);
    void boardCompleted(Board& board);
};

#endif /* SUDOKUCALLBACK_H_ */

