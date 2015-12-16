#include "TFIDFDirectIndex.hpp"

using namespace std;

TFIDFDirectIndex::TFIDFDirectIndex() {}

void TFIDFDirectIndex::addElement(Movie &movie, TFIDFInvertedKey key, int number) {
	multimap<TFIDFDirectKey, list<TFIDFDirectValue> >::iterator it_map;
	
	for(it_map = this->adj.begin(); it_map != this->adj.end(); it_map++) {
		TFIDFDirectKey keyD = it_map->first;
		if(keyD.getMovie().equals(movie)) {
			list<TFIDFDirectValue>::iterator it_list;
			for(it_list = it_map->second.begin(); it_list != it_map->second.end(); it_list++) {
				TFIDFDirectValue* value = &*it_list;
				if(value->getTerm().compare(key.getTerm()) == 0) {
					int frequency = value->getFrequency();
					value->setFrequency(frequency + 1);
				}
			}
			list<TFIDFDirectValue>* values = &it_map->second;
			TFIDFDirectValue newValue;
			newValue.setPosition(key.getItemNumber());
			newValue.setTerm(key.getTerm());
			newValue.setFrequency(number);
			values->push_back(newValue);
		}
	}
	TFIDFDirectKey newKey;
	newKey.setMovie(movie);
	newKey.setMovieNumber(this->adj.size());
	list<TFIDFDirectValue> values;
	TFIDFDirectValue newValue;
	newValue.setPosition(key.getItemNumber());
	newValue.setTerm(key.getTerm());
	newValue.setFrequency(1);
	values.push_back(newValue);
	this->adj.insert(pair<TFIDFDirectKey, list<TFIDFDirectValue> >(newKey,values));
}

list<TFIDFDirectKey> TFIDFDirectIndex::keys() {
	multimap<TFIDFDirectKey, list<TFIDFDirectValue> >::iterator it_map;
	list<TFIDFDirectKey> directKeys;

	for(it_map = this->adj.begin(); it_map != this->adj.end(); it_map++) {
		directKeys.push_back(it_map->first);
	}

	return directKeys;
}

list<TFIDFDirectValue> TFIDFDirectIndex::getValues(Movie movie) {
	multimap<TFIDFDirectKey, list<TFIDFDirectValue> >::iterator it_map;

	for(it_map = this->adj.begin(); it_map != this->adj.end(); it_map++) {
		TFIDFDirectKey key = it_map->first;
		if(key.getMovie().equals(movie)) {
			return it_map->second;
		}
	}
	list<TFIDFDirectValue> empty;

	return empty;
}
