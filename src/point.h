/*
 * point.h
 *
 *  Created on: Feb 24, 2016
 *      Author: Todd
 */

#ifndef POINT_H_
#define POINT_H_
#include "common.h"

// grid (row 0:8, column 0:8) coordinates
class Block;
class Point {
    int rowNo;
    int columnNo;
    int blockNo;
    int blockRowNo;
    int blockColumnNo;
    int index;
public:
    // private base constructor
    Point(int rowNo, int columnNo);
    // convert (box 0:8, blockRowNo 0:2, blockColumnNo 0:2) to
    // grid (row 0:8, column 0:8) coordinates
    Point(int blockNo, int blockRowNo, int blockColumnNo);
    Point(Block& block, int blockRowNo, int blockColumnNo);
    // convert (index 0:80) to
    // grid (row 0:8, column 0:8) coordinates
    Point(int index);
    void initBlock(int rowNo, int columnNo);
    const int getIndex();

    // stringify
    string to_string();

    inline int getColumnNo() const {
        return columnNo;
    }

    inline int getRowNo() const {
        return rowNo;
    }

    inline int getBlockNo() const {
        return blockNo;
    }
};

#endif /* POINT_H_ */
