/*
 * boardcomparison.h
 *
 *  Created on: Feb 24, 2016
 *      Author: Todd
 */

#ifndef BOARDCOMPARISON_H_
#define BOARDCOMPARISON_H_

const bool PQ_ORDER_ASCENDING = true;
const bool PQ_ORDER_DESCENDING = false;
// compare board value:
// - reverse = true  -> order increasing
// - reverse = false -> order decreasing
class Board;

class BoardComparison {
	bool reverse;
public:
	BoardComparison(const bool reverse_ = PQ_ORDER_ASCENDING);
	bool operator()(const Board& lhs, const Board& rhs) const;
};

#endif /* BOARDCOMPARISON_H_ */
