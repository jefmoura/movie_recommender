#include "TFIDFInvertedKey.hpp"

using namespace std;

TFIDFInvertedKey::TFIDFInvertedKey() {
	this->itemNumber = 0;
}
	
string TFIDFInvertedKey::getTerm() {
	return this->term;
}

void TFIDFInvertedKey::setTerm(string term) {
	this->term = term;
}
	
int TFIDFInvertedKey::getItemNumber() {
	return this->itemNumber;
}

void TFIDFInvertedKey::setItemNumber(int itemNumber) {
	this->itemNumber = itemNumber;
}
