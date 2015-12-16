#pragma once
#include <iostream>
#include <cstdlib>
#include <list>
#include <iterator>
#include <string>
#include <map>

#include "../model/Movie.hpp"
#include "TFIDFInvertedKey.hpp"
#include "TFIDFDirectKey.hpp"
#include "TFIDFDirectValue.hpp"

class TFIDFDirectIndex {
	private:
		multimap<TFIDFDirectKey, list<TFIDFDirectValue> > adj;
	
	public:
		TFIDFDirectIndex();
		void addElement(Movie &movie, TFIDFInvertedKey key, int number);
		list<TFIDFDirectKey> keys();
		list<TFIDFDirectValue> getValues(Movie movie);
};