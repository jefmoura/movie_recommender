#include "Rating.hpp"

using namespace std;

Rating::Rating() {}
	
Rating::Rating(User &user, Movie &movie, double score) {
	this->user = user;
	this->movie = movie;
	this->score = score;
}

bool Rating::equals(Rating obj) {
	if((this->movie.getId() == obj.movie.getId()) && (this->user.getId() == obj.user.getId())) {
		return true;
	}
	return false;
}

User Rating::getUser() {
	return user;
}

void Rating::setUser(User user) {
	this->user = user;
}

Movie Rating::getMovie() {
	return movie;
}

void Rating::setMovie(Movie movie) {
	this->movie = movie;
}

double Rating::getScore() {
	return score;
}

void Rating::setScore(double score) {
	this->score = score;
}