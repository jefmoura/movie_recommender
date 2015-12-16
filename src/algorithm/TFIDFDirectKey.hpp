#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include "../model/Movie.hpp"

using namespace std;

class TFIDFDirectKey {
	
	private:
		Movie movie;
		int movieNumber;
	
	public:
		TFIDFDirectKey();
		Movie getMovie();
		void setMovie(Movie movie);
		int getMovieNumber();
		void setMovieNumber(int movieNumber);
		bool operator <(const TFIDFDirectKey& rhs) const {
			return (movieNumber < rhs.movieNumber);
		};
};