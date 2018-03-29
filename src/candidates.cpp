/*
 * candidates.cpp
 *
 *  Created on: Feb 24, 2016
 *      Author: Todd
 */
#include "candidates.h"

Candidates::Candidates() :
                availableCandidates(ALL_CANDIDATES_AVAILABLE),
                nAvailableCandidates(GRID_LENGTH) {
}
Candidates::Candidates(int initValue) :
                availableCandidates(initValue),
                nAvailableCandidates(GRID_LENGTH) {
}

// use default base copy Constructor, assignment operator
string Candidates::to_string() {
    return "0x" + availableCandidates.to_string();
}

// set value as not available (presumably set from row, column, box)
bool Candidates::isAvailable(int value) {
    return (availableCandidates[value] != 0);
}

// number of available candidates
int Candidates::getNAvailableCandidates() {
    return nAvailableCandidates;
}

// set value as not available (presumably set from row, column, box)
void Candidates::removeCandidate(int value) {
    //if (value != CELL_NOVALUE)
    if (availableCandidates[value]) {
        --nAvailableCandidates;
        availableCandidates[value] = 0;
    }
}

// set all values as unavailable
void Candidates::removeAllCandidates() {
    nAvailableCandidates = 0;
    availableCandidates = 0;
}

int Candidates::Iterator::operator*() {
    return value;
}

Candidates::Iterator::Iterator(Candidates& candidates, int value) :
                candidates(candidates),
                value(value) {
}
bool Candidates::Iterator::operator==(const Iterator rhs) {
    return value == rhs.value;
}
bool Candidates::Iterator::operator!=(const Iterator rhs) {
    return value != rhs.value;
}
Candidates::Iterator& Candidates::Iterator::operator++() {
    ++value;
    return *this;
}
Candidates::Iterator Candidates::Iterator::operator++(int) {
    Iterator tmp(*this);
    ++value;
    return tmp;
}
Candidates::Iterator Candidates::begin() {
    Candidates::Iterator iterator(*this, 1);
    return iterator;
}

Candidates::Iterator Candidates::end() {
    Candidates::Iterator iterator(*this, GRID_LENGTH+1);
    return iterator;
}

