#pragma once
#include <iostream>
#include <cstdlib>
#include <list>
#include <iterator>
#include <string>
#include <map>

#include "../model/Movie.hpp"
#include "TFIDFInvertedKey.hpp"
#include "TFIDFInvertedValue.hpp"

class TFIDFInvertedIndex {
	private:
		multimap<TFIDFInvertedKey, list<TFIDFInvertedValue> > adj;
	
	public:
		TFIDFInvertedIndex();
		TFIDFInvertedKey addElement(string term, Movie &movie, int number);
		int sizeOfTerms();
		list<TFIDFInvertedKey> keys();
		list<TFIDFInvertedValue> getValues(string term);
};