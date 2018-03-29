/*
 * common.h
 *
 *  Created on: Feb 5, 2017
 *      Author: kushn_du3a95r
 */

#ifndef COMMON_H_
#define COMMON_H_

const int CANDIDATE_COUNT = 10;
const int BLOCK_LENGTH = 3;
const int GRID_LENGTH = 9;
const int ALL_CANDIDATES_AVAILABLE = 0x03FE;
const int GRID_SIZE = GRID_LENGTH * GRID_LENGTH;
const unsigned int SETTINGS_COUNT = 2;
const unsigned int SETTINGS_MASK = 0;
const unsigned int SETTINGS_ALL_MASK = (2 << SETTINGS_COUNT) - 1;

#include <algorithm>
#include <bitset>
#include <cstring>
#include <functional>     // greater
#include <fstream>
#include <iostream>
#include <iterator>     // iterator, input_iterator_tag
#include <set>
#include <string>
#include <sstream>
#include <queue>          // priority_queue
#include <vector>

#include "unistd.h"
using namespace std;

#endif /* COMMON_H_ */
