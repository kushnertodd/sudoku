/*
 * board.cpp
 *
 *  Created on: Feb 24, 2016
 *      Author: Todd
 */
#include <iomanip>
#include "board.h"

#include "sudokuinit.h"

int Board::idSeq = 0;

Board::Board() :
                nfree(GRID_SIZE),
                lastCellNo(0),
                id(idSeq++) {
}

Board::Board(const Board& board) :
                nfree(board.nfree),
                lastCellNo(0),
                grid(board.grid),
                id(idSeq++) {
}
// find cell that is candidate for having values filled
Cell* Board::nextCell() {
    if (nfree > 0) {
        cout << "Board::nextcell: starting with " << lastCellNo << endl;
        Cell* candidate = NULL;
        for (int next = lastCellNo; next < GRID_SIZE; next++) {
            Cell& cell = grid.cells[next];
            if (!cell.isSet()) {
                cout << "Board::nextCell: cell " << next << " not set" << endl;
                if (candidate == NULL) {
                    candidate = &cell;
                    if (1) { //SudokuInit::debugCell()) {
                        cout << "Board::nextCell: first  " << cell.to_string()
                                << endl;
                    }
                } else {
                    // pick the cell with the fewest available possibilities
                    if (1) { //SudokuInit::debugCell()) {
                        cout << "Board::nextCell: " << cell.to_string()
                                << " not set, no. candidates "
                                << cell.getNAvailableCandidates()
                                << " min so far "
                                << candidate->getNAvailableCandidates() << " "
                                << candidate->to_string() << endl;
                    }
                    if (cell.getNAvailableCandidates()
                            < candidate->getNAvailableCandidates())
                        candidate = &cell;
                }
            } else {
                if (1) //SudokuInit::debugCell()) {
                    cout << "Board::nextCell: " << cell.to_string() << " set"
                            << endl;
            }
        }
        return candidate;
    } else {
        return NULL;
    }
}
bool Board::complete() {
    return (nfree == 0);
}
void Board::print(const char *msg) {
    int idx = 0;
    if (msg != NULL)
        cout << msg << endl;
    cout << endl;
    cout << "id: " << id << " nfree: " << nfree << " lastCellNo: " << lastCellNo
            << endl;
    for (int i = 0; i < BLOCK_LENGTH * BLOCK_LENGTH; i++) {
        if (i % BLOCK_LENGTH == 0)
            cout << " +============+============+============+"
                    << "============+============+============+"
                    << "============+============+============+" << endl
                    << flush;
        else
            cout << " +------------+------------+------------+"
                    << "------------+------------+------------+"
                    << "------------+------------+------------+" << endl
                    << flush;
        int idx_save = idx;
        cout << " #";
        for (int j = 0; j < BLOCK_LENGTH * BLOCK_LENGTH; j++, idx++) {
            cout << dec << setw(6) << grid.cells[idx].getValue() << setw(6)
                    << grid.cells[idx].getCandidates().getNAvailableCandidates()
                    << (j % BLOCK_LENGTH == BLOCK_LENGTH - 1 ? "#" : "|");
        }
        cout << endl << flush;
        /*
         idx = idx_save;
         cout << " #";
         for (int j = 0; j < BLOCK_LENGTH * BLOCK_LENGTH; j++) {
         cout << setw(6)
         << grid.cells[idx++].getCandidates().getNAvailableCandidates()
         << (j % BLOCK_LENGTH == BLOCK_LENGTH - 1 ? "#" : "|");
         }
         cout << endl << flush;
         */
        idx = idx_save;
        cout << " #";
        for (int j = 0; j < BLOCK_LENGTH * BLOCK_LENGTH; j++) {
            cout << grid.cells[idx++].getCandidates().to_string()
                    << (j % BLOCK_LENGTH == BLOCK_LENGTH - 1 ? "#" : "|");
        }
        cout << endl << flush;
    }
    cout << " +============+============+============+"
            << "============+============+============+"
            << "============+============+============+" << endl << flush;
}
void Board::print_short(const char *msg) {
    int idx = 0;
    if (msg != NULL)
        cout << msg << endl;
    cout << endl;
    cout << "id: " << id << " nfree: " << nfree << " lastCellNo: " << lastCellNo
            << endl;
    for (int i = 0; i < BLOCK_LENGTH * BLOCK_LENGTH; i++) {
        if (i % BLOCK_LENGTH == 0)
            cout << " +===+===+===+" << "===+===+===+" << "===+===+===+" << endl
                    << flush;
        else
            cout << " +---+---+---+" << "---+---+---+" << "---+---+---+" << endl
                    << flush;
        int idx_save = idx;
        cout << " #";
        for (int j = 0; j < BLOCK_LENGTH * BLOCK_LENGTH; j++, idx++) {
            cout << dec << setw(3) << grid.cells[idx].getValue()
                    << (j % BLOCK_LENGTH == BLOCK_LENGTH - 1 ? "#" : "|");
        }
        cout << endl << flush;
        /*
         idx = idx_save;
         cout << " #";
         for (int j = 0; j < BLOCK_LENGTH * BLOCK_LENGTH; j++) {
         cout << setw(6)
         << grid.cells[idx++].getCandidates().getNAvailableCandidates()
         << (j % BLOCK_LENGTH == BLOCK_LENGTH - 1 ? "#" : "|");
         }
         cout << endl << flush;
         */
        idx = idx_save;
        cout << " #";
        for (int j = 0; j < BLOCK_LENGTH * BLOCK_LENGTH; j++) {
            cout << grid.cells[idx++].getCandidates().to_string()
                    << (j % BLOCK_LENGTH == BLOCK_LENGTH - 1 ? "#" : "|");
        }
        cout << endl << flush;
    }
    cout << " +===+===+===+" << "===+===+===+" << "===+===+===+" << endl
            << flush;
}
void Board::set(int rowNo, int columnNo, int candidate) {
    Point point(rowNo, columnNo);
    set(point, candidate);
}

Cell& Board::getCell(Point& point) {
    return grid.getCell(point);
}
// assign new cell value to board
void Board::set(Point& point, int candidate) {
    Cell& cell = getCell(point);
    if (SudokuInit::debugCell())
        cout << "Board::set " << cell.to_string() << " to value " << candidate
                << " nfree before: " << nfree << endl;
// check if cell value has no value
    if (!cell.isSet()) {
        if (candidate != 0) {
            if (SudokuInit::debugCell())
                cout << "Board::set before " << cell.to_string() << " to value "
                        << candidate << " nfree: " << nfree << endl;
            cell.set(candidate);
            --nfree;
            if (SudokuInit::debugCell())
                cout << "Board::set after  " << cell.to_string() << " nfree: "
                        << nfree << endl;
            Row row(grid, point.getRowNo());
            for (RowIterator iter = row.begin(); iter != row.end(); iter++) {
                Point iterPoint = (*iter);
                Cell& iterCell = getCell(iterPoint);
                if (iterPoint.getColumnNo() != point.getColumnNo()) {
                    if (iterCell.isSet()) {
                        if (SudokuInit::debugCell())
                            cout
                                    << "  Board::set rowNo:    cell already set to "
                                    << " " << iterCell.getValue() << "    "
                                    << iterPoint.to_string() << " "
                                    << iterCell.getCandidates().getAvailableCandidates()
                                    << endl;
                    } else {
                        iterCell.getCandidates().removeCandidate(candidate);
                        if (SudokuInit::debugCell())
                            cout << "  Board::set rowNo:    removing candidate "
                                    << candidate << " of "
                                    << iterCell.getCandidates().getNAvailableCandidates()
                                    << " " << iterCell.getPoint().to_string()
                                    << " "
                                    << iterCell.getCandidates().getAvailableCandidates()
                                    << endl;
                    }
                } else {
                    if (SudokuInit::debugCell())
                        cout
                                << "  Board::set rowNo:    skipping original point   "
                                << iterCell.getPoint().to_string() << endl;
                }
            }
            Column column = Column::create(grid, point.getColumnNo());
            for (ColumnIterator iter = column.begin(); iter != column.end();
                    iter++) {
                Point iterPoint = (*iter);
                Cell& iterCell = getCell(iterPoint);
                if (iterPoint.getRowNo() != point.getRowNo()) {
                    if (iterCell.isSet()) {
                        if (SudokuInit::debugCell())
                            cout
                                    << "  Board::set columnNo: cell already set to "
                                    << " " << iterCell.getValue() << "    "
                                    << iterPoint.to_string() << " "
                                    << iterCell.getCandidates().getAvailableCandidates()
                                    << endl;
                    } else {
                        iterCell.getCandidates().removeCandidate(candidate);
                        if (SudokuInit::debugCell())
                            cout << "  Board::set columnNo: removing candidate "
                                    << candidate << " of "
                                    << iterCell.getCandidates().getNAvailableCandidates()
                                    << " " << iterPoint.to_string() << " "
                                    << iterCell.getCandidates().getAvailableCandidates()
                                    << endl;
                    }
                } else {
                    if (SudokuInit::debugCell())
                        cout
                                << "  Board::set columnNo: skipping original point   "
                                << iterPoint.to_string() << endl;
                }
            }
            Block block(grid, point.getBlockNo());
            for (Block::Iterator iter = block.begin(); iter != block.end();
                    iter++) {
                Point iterPoint = (*iter);
                Cell& iterCell = getCell(iterPoint);
                if (iterPoint.getRowNo() != point.getRowNo()
                        || iterPoint.getColumnNo() != point.getColumnNo()) {
                    if (iterCell.isSet()) {
                        if (SudokuInit::debugCell())
                            cout
                                    << "  Board::set block:    cell already set to "
                                    << " " << iterCell.getValue() << "    "
                                    << iterCell.getPoint().to_string() << " "
                                    << iterCell.getCandidates().getAvailableCandidates()
                                    << endl;
                    } else {
                        iterCell.getCandidates().removeCandidate(candidate);
                        if (SudokuInit::debugCell())
                            cout << "  Board::set block:    removing candidate "
                                    << candidate << " of "
                                    << iterCell.getCandidates().getNAvailableCandidates()
                                    << " " << iterPoint.to_string() << " "
                                    << iterCell.getCandidates().getAvailableCandidates()
                                    << endl;
                    }
                } else {
                    if (SudokuInit::debugCell())
                        cout
                                << "  Board::set block:    skipping original point   "
                                << iterPoint.to_string() << endl;
                }
            }
        }
    } else {
        cout << "Board::set error: getCell (" << point.getRowNo() << ", "
                << point.getColumnNo() << ") = " << cell.getValue()
                << " being set to " << candidate << endl;
    }
}
// for now, a simple evaluation function: best = less free cells
int Board::value() const {
    return nfree;
}

