#include "TFIDFDirectValue.hpp"

using namespace std;

TFIDFDirectValue::TFIDFDirectValue() {}
	
int TFIDFDirectValue::getPosition() {
	return this->position;
}

void TFIDFDirectValue::setPosition(int position) {
	this->position = position;
}
	
string TFIDFDirectValue::getTerm() {
	return this->term;
}

void TFIDFDirectValue::setTerm(string term) {
	this->term = term;
}
	
int TFIDFDirectValue::getFrequency() {
	return this->frequency;
}

void TFIDFDirectValue::setFrequency(int frequency) {
	this->frequency = frequency;
}
