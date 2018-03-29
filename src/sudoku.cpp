//============================================================================
// Name        : sudoku.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "sudoku.h"

// initialize board with numbers
// initialize priority queue with board(evaluation function)
// while (!empty of priority queue)
//   board = priority queue.pop()
//   if (board.complete())
//     board.print();
//     if (first_only)
//       break
//   else
//     next_cell = board.nextCell()
//     new_possibilities = next_cell.possibilities()
//     for (iter = new_possibilities.begin();
//          iter != new_possibilities.end();
//          iter++)
//       new_board = Board(board).add(*iter)

Sudoku::Sudoku(SudokuCallback& sudokuCallback) :
                sudokuCallback(sudokuCallback) {
}

void Sudoku::init(int argc, char **argv) {
    sudokuInit.parseArgs(argc, argv);
    Board board;
    sudokuInit.readBoard(board);
    if (SudokuInit::debugBoard())
        cout << "Sudoku::init: push board " << endl;
    pq.push(board);
}

void Sudoku::process() {
    if (SudokuInit::debugBoard())
        cout << "Sudoku::process: test empty " << endl;
    while (!pq.empty()) {
        if (SudokuInit::debugBoard())
            cout << "Sudoku::process: not empty " << endl;
        Board nextBoard = pq.top();  // Print highest priority board
        pq.pop();  // Remove highest priority board
        if (SudokuInit::debugBoard())
            nextBoard.print("Sudoku::process: next highest priority board");
        if (nextBoard.complete()) {
            if (1)//(SudokuInit::debugBoard())
                nextBoard.print_short("Sudoku::process: board complete");
            break; // assume only one solution, or others are reflections
        } else {
            Cell* nextCell = nextBoard.nextCell();
            if (1)//(SudokuInit::debugCell())
                cout << endl << "Sudoku::process trying next cell: "
                        << (nextCell == NULL ? "NULL" : nextCell->to_string())
                        << endl;
            if (nextCell == NULL) {
                cout << "Sudoku::process error getting next cell" << endl;
            } else {
                Point& point = nextCell->getPoint();
                Candidates& candidates = nextCell->getCandidates();
                cout << "Sudoku::process candidates " << candidates.to_string() << endl;
                for (Candidates::Iterator iter = candidates.begin();
                        iter != candidates.end(); iter++) {
                    int candidate = *iter;
                    cout << "Sudoku::process  looking at candidate "
                            << candidate << endl;
                    if (candidates.isAvailable(candidate)) {
                        cout << "Sudoku::process setting candidate "
                                << candidate << " of " << nextCell->to_string()
                                << endl;
                        Board candidateBoard(nextBoard);
                        candidateBoard.set(point, candidate);
                        if (SudokuInit::debugBoard())
                            candidateBoard.print();
                        pq.push(candidateBoard);
                    } else {
                        cout << "Sudoku::process  candidate " << candidate
                                << " unavailable" << endl;

                    }
                }
            }
        }
    }
    if (SudokuInit::debugBoard())
        cout << "Sudoku::process: empty " << endl;

}
