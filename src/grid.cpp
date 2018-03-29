/*
 * grid.cpp
 *
 *  Created on: Feb 24, 2016
 *      Author: Todd
 */
#include "grid.h"
// 9x9 grid of cells
Grid::Grid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        cells.push_back(Cell(i));
    }
}
Grid::Grid(const Grid& grid_) {
    for (int i = 0; i < GRID_SIZE; i++) {
        Cell cell(grid_.cells[i]);
        cells.push_back(cell);
    }
}

// return cell by row 0:8, column 0:8 coordinates
Cell& Grid::getCell(Point& point) {
    int index = point.getIndex();
    return cells[index];
}


