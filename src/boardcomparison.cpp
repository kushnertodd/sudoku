/*
 * boardcomparison.cpp
 *
 *  Created on: Feb 24, 2016
 *      Author: Todd
 */
#include "boardcomparison.h"
#include "board.h"

//BoardComparison(const bool& reverse_=PQ_ORDER_ASCENDING) {
BoardComparison::BoardComparison(const bool reverse_) {
	reverse = reverse_;
}
bool BoardComparison::operator()(const Board& lhs, const Board& rhs) const {
	return (reverse ? lhs.value() > rhs.value() : lhs.value() < rhs.value());
}

