/*
 * row.cpp
 *
 *  Created on: Feb 24, 2016
 *      Author: Todd
 */
#include "row.h"

Row::Iterator::Iterator(Row& row, int columnNo) :
                row(row),
                columnNo(columnNo) {
}
Row::Iterator::Iterator(const Iterator& iter) :
                row(iter.row),
                columnNo(iter.columnNo) {
}
Row::Iterator& Row::Iterator::operator++() {
    ++columnNo;
    return *this;
}
Row::Iterator Row::Iterator::operator++(int) {
    Iterator tmp(*this);
    ++columnNo;
    return tmp;
}
bool Row::Iterator::operator==(const Iterator rhs) {
    return columnNo == rhs.columnNo;
}
bool Row::Iterator::operator!=(const Iterator rhs) {
    return columnNo != rhs.columnNo;
}
Point Row::Iterator::operator*() {
    Point point(row.rowNo, columnNo);
    return point;
}
Row::Row(const Row& row) :
                grid(row.grid),
                rowNo(row.rowNo) {
}
Row::Row(Grid& grid, int rowNo) :
                grid(grid),
                rowNo(rowNo) {
}
Row& Row::operator=(const Row& row) {
    grid = row.grid;
    rowNo = row.rowNo;
    return *this;
}
Row::Iterator Row::begin() {
    return Iterator(*this, 0);
}
Row::Iterator Row::end() {
    return Iterator(*this, GRID_LENGTH);
}
Cell& Row::getCell(int columnNo) {
    Point point(rowNo, columnNo);
    return grid.getCell(point);
}
// stringify
string Row::toString() {
    ostringstream ostr;
    ostr << "row (" << rowNo << ")";
    return ostr.str();
}
