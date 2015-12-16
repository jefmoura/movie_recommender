#include "TFIDFInvertedValue.hpp"

using namespace std;

TFIDFInvertedValue::TFIDFInvertedValue() {}
	
int TFIDFInvertedValue::getPosition() {
	return this->position;
}

void TFIDFInvertedValue::setPosition(int position) {
	this->position = position;
}
	
Movie TFIDFInvertedValue::getMovie() {
	return this->movie;
}

void TFIDFInvertedValue::setMovie(Movie movie) {
	this->movie = movie;
}
	
int TFIDFInvertedValue::getFrequency() {
	return this->frequency;
}

void TFIDFInvertedValue::setFrequency(int frequency) {
	this->frequency = frequency;
}

int frequencyBy(list<TFIDFInvertedValue> &values, int position) {
		for(list<TFIDFInvertedValue>::iterator value = values.begin(); value != values.end(); value++) {
			if(value->getPosition() == position) {
				return value->getFrequency();
			}
		}
		return 0;
}
