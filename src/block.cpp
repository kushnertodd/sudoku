/*
 * block.cpp
 *
 *  Created on: Feb 24, 2016
 *      Author: Todd
 */
#include "block.h"
Block::Iterator::Iterator(Block& block, int blockRowNo, int blockColumnNo) :
                block(block),
                blockRowNo(blockRowNo),
                blockColumnNo(blockColumnNo) {
}
Block::Iterator::Iterator(const Iterator& iter) :
                block(iter.block),
                blockRowNo(iter.blockRowNo),
                blockColumnNo(iter.blockColumnNo) {
}
Block::Iterator Block::Iterator::operator++() {
    ++blockColumnNo;
    if (blockColumnNo == BLOCK_LENGTH) {
        blockColumnNo = 0;
        blockRowNo++;
    }
    return *this;
}
Block::Iterator Block::Iterator::operator++(int) {
    Iterator tmp(*this);
    ++blockColumnNo;
    if (blockColumnNo == BLOCK_LENGTH) {
        blockColumnNo = 0;
        blockRowNo++;
    }
    return tmp;
}
bool Block::Iterator::operator==(Iterator rhs) {
    return blockRowNo == rhs.blockRowNo && blockColumnNo == rhs.blockColumnNo;
}
bool Block::Iterator::operator!=(Iterator rhs) {
    return blockRowNo != rhs.blockRowNo || blockColumnNo != rhs.blockColumnNo;
}
Point Block::Iterator::operator*() {
    Point point(block.blockNo, blockRowNo, blockColumnNo);
    return point;
}
Block::Block(const Block& block) :
                grid(block.grid),
                blockNo(block.blockNo) {
}
Block::Block(Grid& grid, int blockNo) :
                grid(grid),
                blockNo(blockNo) {
}
Block& Block::operator=(const Block& block_) {
    grid = block_.grid;
    blockNo = block_.blockNo;
    return *this;
}
Block::Iterator Block::begin() {
    return Iterator(*this, 0, 0);
}
Block::Iterator Block::end() {
    return Iterator(*this, BLOCK_LENGTH, 0);
}

// stringify
string Block::toString() {
    ostringstream ostr;
    ostr << "block (" << blockNo << ")";
    return ostr.str();
}

