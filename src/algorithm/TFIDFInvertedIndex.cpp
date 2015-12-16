#include "TFIDFInvertedIndex.hpp"

using namespace std;

TFIDFInvertedIndex::TFIDFInvertedIndex() {}
	
TFIDFInvertedKey TFIDFInvertedIndex::addElement(string term, Movie &movie, int number) {
	multimap<TFIDFInvertedKey, list<TFIDFInvertedValue> >::iterator it_map;

	for(it_map = this->adj.begin(); it_map != this->adj.end(); it_map++) {
		TFIDFInvertedKey key = it_map->first;
		if(key.getTerm().compare(term) == 0) {
			list<TFIDFInvertedValue>::iterator it_list;
			for(it_list = it_map->second.begin(); it_list != it_map->second.end(); it_list++) {
				TFIDFInvertedValue* value = &*it_list;
				if(value->getMovie().equals(movie)) {
					int frequency = value->getFrequency();
					value->setFrequency(frequency + 1);
					return key;
				}
			}
			list<TFIDFInvertedValue>* values = &it_map->second;
			TFIDFInvertedValue newValue;
			newValue.setPosition(values->size());
			newValue.setMovie(movie);
			newValue.setFrequency(number);
			values->push_back(newValue);
			return key;
		}
	}

	TFIDFInvertedKey key;
	key.setTerm(term);
	key.setItemNumber(this->adj.size());
	list<TFIDFInvertedValue> values;
	TFIDFInvertedValue newValue;
	newValue.setPosition(0);
	newValue.setMovie(movie);
	newValue.setFrequency(1);
	values.push_back(newValue);
	this->adj.insert(pair<TFIDFInvertedKey, list<TFIDFInvertedValue> >(key, values));
	return key;
}

int TFIDFInvertedIndex::sizeOfTerms() {
	return this->adj.size();
}

list<TFIDFInvertedKey> TFIDFInvertedIndex::keys() {
	multimap<TFIDFInvertedKey, list<TFIDFInvertedValue> >::iterator it_map;
	list<TFIDFInvertedKey> invertedKeys;

	for(it_map = this->adj.begin(); it_map != this->adj.end(); it_map++) {
		invertedKeys.push_back(it_map->first);
	}

	return invertedKeys;
}

list<TFIDFInvertedValue> TFIDFInvertedIndex::getValues(string term) {
	multimap<TFIDFInvertedKey, list<TFIDFInvertedValue> >::iterator it_map;

	for(it_map = this->adj.begin(); it_map != this->adj.end(); it_map++) {
		TFIDFInvertedKey key = it_map->first;
		if(key.getTerm().compare(term) == 0) {
			return it_map->second;
		}
	}
	list<TFIDFInvertedValue> empty;

	return empty;
}