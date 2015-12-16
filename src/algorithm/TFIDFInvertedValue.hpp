#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include "../model/Movie.hpp"

using namespace std;

class TFIDFInvertedValue {
	
	private:
		int position;
		Movie movie;
		int frequency;
	
	public:
		TFIDFInvertedValue();
		int getPosition();
		void setPosition(int position);
		Movie getMovie();
		void setMovie(Movie movie);
		int getFrequency();
		void setFrequency(int frequency);
	
};

int frequencyBy(list<TFIDFInvertedValue> &values, int position);