/*
 * cell.cpp
 *
 *  Created on: Feb 24, 2016
 *      Author: Todd
 */
#include "cell.h"
/*
 * Cell available values:
 * - valid values are 1..9, 0 = no value
 * - bitmask possibilities_ indicates possible values while no
 *   value set
 */
// constructor: n 0..GRID_AREA-1
Cell::Cell(int index) :
                point(index),
                value(0) {
}
//Cell::Cell(Point point) : point(point) {}
Cell::Cell(const Cell& cell) :
                point(cell.point),
                candidates(cell.candidates),
                value(cell.value) {
}

// cell assigned a value?
bool Cell::isSet() {
    return getNAvailableCandidates() == 0;
}
// set cell to a value
void Cell::set(int value_) {
    setValue(value_);
    candidates.removeAllCandidates();
}

// candidate values
Candidates& Cell::getCandidates() {
    return candidates;
}
// number of free candidates
int Cell::getNAvailableCandidates() {
    return candidates.getNAvailableCandidates();
}
string Cell::to_string() {
    ostringstream ostr;
    ostr << "cell " << point.to_string() << " value " << value << " nvalues "
            << candidates.getNAvailableCandidates() << " hex 0x" << hex
            << candidates.getAvailableCandidates();
    return ostr.str();
}

