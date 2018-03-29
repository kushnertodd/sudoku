#include "point.h"

// grid (row 0:8, column 0:8) coordinates
// private base constructor
Point::Point(int rowNo, int columnNo) :
                rowNo(rowNo),
                columnNo(columnNo) {
    initBlock(rowNo, columnNo);
}

// convert (block 0:8, blockrow 0:2, blockcolumn 0:2) to
// grid (row 0:8, column 0:8) coordinates
Point::Point(int blockNo, int blockRowNo, int blockColumnNo) :
                blockNo(blockNo),
                blockRowNo(blockRowNo),
                blockColumnNo(blockColumnNo) {
    // convert block coordinate (0:8) to block offsets (0:2, 0:2)
    int xBoxOffset = blockNo % BLOCK_LENGTH;
    int yBoxOffset = blockNo / BLOCK_LENGTH;
    // get 3x3 block upper left-hand corners (0:6, 0:6)
    int xBoxUlc = xBoxOffset * BLOCK_LENGTH;
    int yBoxUlc = yBoxOffset * BLOCK_LENGTH;
    // convert to (0:8, 0:8) grid coordinates
    rowNo = yBoxUlc + blockRowNo;
    columnNo = xBoxUlc + blockColumnNo;
    index = rowNo * GRID_LENGTH + columnNo;
}
/*
Point Point::create(int blockNo, int blockRowNo, int blockColumnNo) {
    Point point(int blockNo, int blockRowNo, int blockColumnNo);
    return point;
}
*/
// convert (index 0:80) to
// grid (row 0:8, column 0:8) coordinates
Point::Point(int index) :
                index(index) {
    rowNo = (index / GRID_LENGTH);
    columnNo = (index % GRID_LENGTH);
    initBlock(rowNo, columnNo);
}
void Point::initBlock(int rowNo, int columnNo) {
// the (row, column) to box mapping is:
    blockNo = (rowNo / BLOCK_LENGTH) * BLOCK_LENGTH + columnNo / BLOCK_LENGTH;
// get 3x3 box offsets  (0:2, 0:2)
    blockRowNo = rowNo % BLOCK_LENGTH;
    blockColumnNo = columnNo % BLOCK_LENGTH;
}
const int Point::getIndex() {
    return rowNo * GRID_LENGTH + columnNo;
}
// stringify
string Point::to_string() {
    ostringstream ostr;
    ostr << "(" << rowNo << ", " << columnNo << ")";
    return ostr.str();
}
