#include "Util.hpp"

using namespace std;

int Util::frequencyBy(list<TFIDFInvertedValue> values, int position) {
		for(list<TFIDFInvertedValue>::iterator value = values.begin(); value != values.end(); value++) {
			if(value->getPosition() == position) {
				return value->getFrequency();
			}
		}
		return 0;
}