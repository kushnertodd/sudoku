/*
 * sudokuparse.h
 *
 *  Created on: Feb 24, 2016
 *      Author: Todd
 */

#ifndef SUDOKUINIT_H_
#define SUDOKUINIT_H_

#include "common.h"
#include "board.h"
using namespace std;

class Board;
class SudokuInit {
public:
    string file;
    enum Settings {
        DEBUG_CELL_SET, DEBUG_BOARD_SET
    };
    static bitset<SETTINGS_COUNT> settings;

    void parseArgs(int argc, char **argv);
    void readBoard(Board& board);
    static bool debugCell();
    static bool debugBoard();
};

#endif /* SUDOKUINIT_H_ */
