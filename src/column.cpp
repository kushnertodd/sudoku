/*
 * column.cpp
 *
 *  Created on: Feb 24, 2016
 *      Author: Todd
 */

#include "column.h"

Column::Iterator::Iterator(Column& column_, int rowNo_) :
                column(column_),
                rowNo(rowNo_) {
}
Column::Iterator::Iterator(const Iterator& iter) :
                column(iter.column),
                rowNo(iter.rowNo) {
}
Column::Iterator& Column::Iterator::operator++() {
    ++rowNo;
    return *this;
}
Column::Iterator Column::Iterator::operator++(int) {
    Iterator tmp(*this);
    ++rowNo;
    return tmp;
}
bool Column::Iterator::operator==(Iterator rhs) {
    return rowNo == rhs.rowNo;
}
bool Column::Iterator::operator!=(Iterator rhs) {
    return rowNo != rhs.rowNo;
}
Point Column::Iterator::operator*() {
    Point point(rowNo, column.columnNo);
    return point;
}
Column::Column(const Column& column_) :
                grid(column_.grid),
                columnNo(column_.columnNo) {
}
Column::Column(Grid& grid_, int columnNo_) :
                grid(grid_),
                columnNo(columnNo_) {
}
Column create(const Column column_) {
    Column column(column_);
    return column;
}
Column Column::create(Grid& grid_, int columnNo_) {
    return Column(grid_, columnNo_);
}
Column& Column::operator=(const Column& column) {
    grid = column.grid;
    columnNo = column.columnNo;
    return *this;
}
Column::Iterator Column::begin() {
    return Iterator(*this, 0);
}
Column::Iterator Column::end() {
    return Iterator(*this, GRID_LENGTH);
}
Cell& Column::getCell(int rowNo) {
    Point point(rowNo, columnNo);
    return grid.getCell(point);
}
// stringify
string Column::toString() {
    ostringstream ostr;
    ostr << "column (" << columnNo << ")";
    return ostr.str();
}

