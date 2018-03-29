/*
 * sudokuparse.cpp
 *
 *  Created on: Feb 24, 2016
 *      Author: Todd
 */
#include "sudokuinit.h"

bool SudokuInit::debugCell() {
    return 1;//settings[DEBUG_CELL_SET];
}

bool SudokuInit::debugBoard() {
    return 1;//settings[DEBUG_BOARD_SET];
}

bitset<SETTINGS_COUNT> SudokuInit::settings = 3;

void SudokuInit::parseArgs(int argc, char **argv) {
    file = "sudoku.txt";

    //getcwd(dir, 1000);
    for (int arg = 1; arg < argc; arg++) {
        cout << "arg " << arg << " = " << argv[arg] << endl;
        if (!strcmp(argv[arg], "-dc")) {
            settings[DEBUG_CELL_SET] = 1;
        } else if (!strcmp(argv[arg], "-db")) {
            settings[DEBUG_BOARD_SET] = 1;
        } else {
            file = argv[arg];
        }
    }
}

//  parse suduko input file:
//    0 0 0   1 1 1   1 2 2
//  0123456789012345678901234
// 0+-------+-------+-------+
//01| 2 . 6 | 1 . 7 | 4 . 8 |
//02| 3 7 . | . 4 . | . 5 6 |
//03| . 1 . | . 8 . | . 3 . |
// 4+-------+-------+-------+
//05| . 8 3 | 9 . 2 | 5 6 . |
//06| 5 . 4 | 3 6 1 | 7 . 2 |
//07| . . . | 8 . 4 | . . . |
// 8+-------+-------+-------+
//09| 8 . 1 | . . . | 6 . 9 |
//00| . . . | 6 . 8 | . . . |
//11| 7 6 . | 4 9 3 | . 2 1 |
// 2+-------+-------+-------+
void SudokuInit::readBoard(Board& board) {
    ifstream myfile;
    file = "sudoku.txt";

    myfile.open(file.c_str());
    string line;
    int columns[GRID_LENGTH] = { 2, 4, 6, 10, 12, 14, 18, 20, 22 };
    if (debugCell())
        board.print("SudokuInit::readBoard grid before parsing file");
    for (int lineNo = 0, rowNo = 0; lineNo < 13; lineNo++) {
        getline(myfile, line);
        /*
         if (strlen(line) > 22)
         throw new Exception("line too long");
         */
        if (lineNo % 4 != 0) { // lineNo not in (0, 4, 8, 12)
            if (debugCell())
                cout << "SudokuInit::readBoard line " << lineNo << " rowNo "
                        << rowNo << ": " << line << endl;
            for (int columnNo = 0; columnNo < GRID_LENGTH; columnNo++) {
                if (debugCell())
                    cout << "SudokuInit::readBoard     column " << columnNo
                            << " offset " << std::dec << columns[columnNo]
                            << ": " << line[columns[columnNo]] << " (row "
                            << rowNo << ", column " << columnNo << ")" << endl;
                char val = line[columns[columnNo]];
                if (val != '.') {
                    board.set(rowNo, columnNo, (int) val - (int) '0');
                    if (debugBoard())
                        board.print();
                }
            }
            rowNo++;
        }
    }
    myfile.close();
    if (debugBoard())
        board.print("SudokuInit::readBoard");
}

