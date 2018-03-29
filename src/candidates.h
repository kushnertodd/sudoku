/*
 * possibilities.h
 *
 *  Created on: Feb 24, 2016
 *      Author: Todd
 */

#ifndef CANDIDATES_H_
#define CANDIDATES_H_
#include "common.h"

// allow setting to 1:GRID_EXTENT
typedef bitset<CANDIDATE_COUNT> AvailableCandidates;

class Candidates {
private:
    AvailableCandidates availableCandidates;
    // number of values currently available (0:9)
    int nAvailableCandidates;
public:
    // constructor
    Candidates();
    Candidates(int initValue);
    // use default base copy Constructor, assignment operator
    //ValuesAvailable intersect(ValuesAvailable valuesAvailable_);
    string to_string();
    // is value as available?
    bool isAvailable(int candidates);
    // number of available candidates
    int getNAvailableCandidates();
    // set value as not available (presumably set from row, column, box)
    void removeCandidate(int value);
    // cell is set to a value
    void removeAllCandidates();
    // return set of values for e.g. iterating over
    class Iterator;
    Iterator begin();
    Iterator end();

    inline const AvailableCandidates& getAvailableCandidates() const {
        return availableCandidates;
    }
};
// return set of values for e.g. iterating over
class Candidates::Iterator {
    Candidates& candidates;
    int value;
public:
    Iterator(Candidates& candidates, int value);
    Iterator& operator++();
    Iterator operator++(int);
    bool operator==(const Iterator rhs);
    bool operator!=(const Iterator rhs);
    int operator*();
};
#endif /* CANDIDATES_H_ */
