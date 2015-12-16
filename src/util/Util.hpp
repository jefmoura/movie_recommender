#pragma once
#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <iterator>
#include "../algorithm/TFIDFInvertedValue.hpp"

using namespace std;

class Util {

	public:
		static int frequencyBy(list<TFIDFInvertedValue> values, int position);

};