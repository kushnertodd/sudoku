/*
 * column.h
 *
 *  Created on: Feb 24, 2016
 *      Author: Todd
 */

#ifndef COLUMN_H_
#define COLUMN_H_
#include "common.h"
#include "cell.h"
#include "grid.h"

class Grid;
class Column {
    Grid& grid;
    int columnNo;
public:
    Column(Grid& grid_, int columnNo_);
    Column(const Column& column_);
    class Iterator: iterator<input_iterator_tag, int> {
        Column& column;
        int rowNo;
    public:
        Iterator(Column& column_, int rowNo_);
        Iterator(const Iterator& iter);
        Iterator& operator++();
        Iterator operator++(int);
        bool operator==(Iterator rhs);
        bool operator!=(Iterator rhs);
        Point operator*();
    };
    static Column create(const Column column_);
    static Column create(Grid& grid_, int columnNo_);
    Column& operator=(const Column& column);
    Iterator begin();
    Iterator end();
    Cell& getCell(int rowNo);
    string toString();
};

typedef Column::Iterator ColumnIterator;
typedef vector<Column> ColumnVector;

#endif /* COLUMN_H_ */
