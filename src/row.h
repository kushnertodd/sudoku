/*
 * row.h
 *
 *  Created on: Feb 24, 2016
 *      Author: Todd
 */

#ifndef ROW_H_
#define ROW_H_
#include "common.h"
#include "cell.h"
#include "grid.h"

class Row {
    Grid& grid;
    int rowNo;
public:
    Row(Grid& grid, int rowNo);
	Row(const Row& row);
	class Iterator: iterator<input_iterator_tag, int> {
	public:
		Row& row;
		int columnNo;
		Iterator(Row& row, int columnNo);
		Iterator(const Iterator& iter);
		Iterator& operator++();
		Iterator operator++(int);
		bool operator==(const Iterator rhs);
		bool operator!=(const Iterator rhs);
		Point operator*();
	};
	Row& operator=(const Row& row_);
	Iterator begin();
	Iterator end();
	Cell& getCell(int columnNo);
	string toString();
};

typedef Row::Iterator RowIterator;
typedef vector<Row> RowVector;

#endif /* ROW_H_ */
