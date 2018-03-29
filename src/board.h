/*
 * board.h
 *
 *  Created on: Feb 24, 2016
 *      Author: Todd
 */

#ifndef BOARD_H_
#define BOARD_H_
#include "common.h"
#include "block.h"
#include "grid.h"
#include "row.h"
#include "column.h"
#include "cell.h"
#include "boardcomparison.h"

class Board {
private:
    Grid grid;
    // invariant: nfree = no. of unassigned cells
    int nfree;
    int lastCellNo;
    int id;
public:
    static int idSeq;
    Board();
    Board(const Board& board);
    void load(string& file);
    // find cell that is candidate for having values filled
    Cell* nextCell();
    bool complete();
    void print(const char *msg = NULL);
    void print_short(const char *msg);
    void printAvailable();
    void printnAvailableValues();
    // assign new cell value to board
    void set(Point& point, int value);
    // assign new cell value to board
    void set(int rowNo, int columnNo, int value);
    // for now, a simple evaluation function: best = less free cells
    int value() const;
    Cell& getCell(Point& point);
};

typedef vector<Board> BoardList;
typedef priority_queue<Board, BoardList, BoardComparison> BoardPQ;

#endif /* BOARD_H_ */
