/*
 * cell.h
 *
 *  Created on: Feb 24, 2016
 *      Author: Todd
 */

#ifndef CELL_H_
#define CELL_H_
#include "common.h"
#include "point.h"
#include "candidates.h"

/*
 * Cell available values:
 * - valid values are 1..9, 0 = no value
 * - bitmask possibilities_ indicates possible values while no
 *   value set
 */
class Cell {
    Point point;
    Candidates candidates;
    int value;
public:
    Cell(int n);
    Cell(const Cell& cell);
    // cell assigned a value?
    bool isSet();
    // set cell to a value
    void set(int value);
    // candidate values
    Candidates& getCandidates();
    // number of free candidates
    int getNAvailableCandidates();
    // set value as unavailable for cell
    void unavailable(int value_);
    // stringify
    string to_string();

    inline Point& getPoint()  {
        return point;
    }

    inline int getValue() const {
        return value;
    }

    void setCandidates(const Candidates& candidates) {
        this->candidates = candidates;
    }

    void setPoint(const Point& point) {
        this->point = point;
    }

    void setValue(int value) {
        this->value = value;
    }
};

typedef vector<Cell> CellVector;
typedef CellVector::iterator CellVectorIterator;

#endif /* CELL_H_ */
