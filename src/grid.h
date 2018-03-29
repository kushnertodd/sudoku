/*
 * grid.h
 *
 *  Created on: Feb 24, 2016
 *      Author: Todd
 */

#ifndef GRID_H_
#define GRID_H_

#include "cell.h"
#include "point.h"

// 9x9 grid of cells
//class Index;
class Point;
//class BoxCell;
class Grid {
public:
    CellVector cells;
    Grid();
    Grid(const Grid& grid_);
    // return cell by index 0:63
    //Cell& getCell(const Index& index);
    // return cell by row 0:8, column 0:8 coordinates
    Cell& getCell(Point& point);
    // return cell by box 0:8, boxrow 0:2, boxcolumn 0:2 coordinates
    //Cell& getCell(const BoxCell& boxCell);
};

#endif /* GRID_H_ */
