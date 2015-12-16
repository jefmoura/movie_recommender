#include "TFIDFDirectKey.hpp"

using namespace std;

TFIDFDirectKey::TFIDFDirectKey() {
	this->movieNumber = 0;
}
	
Movie TFIDFDirectKey::getMovie() {
	return this->movie;
}

void TFIDFDirectKey::setMovie(Movie movie) {
	this->movie = movie;
}
	
int TFIDFDirectKey::getMovieNumber() {
	return this->movieNumber;
}

void TFIDFDirectKey::setMovieNumber(int movieNumber) {
	this->movieNumber = movieNumber;
}
