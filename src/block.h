/*
 * block.h
 *
 *  Created on: Feb 24, 2016
 *      Author: Todd
 */

#ifndef block_H_
#define block_H_
#include "common.h"
#include "cell.h"
#include "grid.h"

class Grid;
class Block {
    Grid& grid;
    int blockNo;
public:
	Block(const Block& block);
	Block(Grid& grid, int blockNo);
	class Iterator: iterator<input_iterator_tag, int> {
	public:
		Block& block;
		int blockRowNo, blockColumnNo;
		Iterator(Block& block, int blockRowNo, int blockColumnNo);
		Iterator(const Iterator& iter);
		Iterator operator++();
		Iterator operator++(int);
		bool operator==(Iterator rhs);
		bool operator!=(Iterator rhs);
		Point operator*();
	};

	Block& operator=(const Block& block);
	Iterator begin();
	Iterator end();
	//Cell& cell(int blockRow, int blockColumn);
	string toString();

};

typedef Block::Iterator BlockIterator;
typedef vector<Block> BlockVector;

#endif /* block_H_ */
