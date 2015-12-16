#include "Matrix.hpp"

using namespace std;

Matrix::Matrix() {}

Matrix::Matrix(list<Rating> &ratings) {
	for(list<Rating>::iterator r=ratings.begin(); r!=ratings.end(); r++) {
		pair<int, int> pair = make_pair(r->getUser().getId(), r->getMovie().getId());
		this->matrix[pair] = r->getScore();
	}
}

double Matrix::rating(User &user, Movie &movie) {
	pair<int, int> pair = make_pair(user.getId(), movie.getId());
	if(this->matrix.find(pair) != this->matrix.end()) {
		return this->matrix[pair];
	}
	return 0;
}
	
double Matrix::rating(int termIndex, User user) {
	pair<int, int> pair = make_pair(termIndex, user.getId());
	if(this->matrix.find(pair) != this->matrix.end()) {
		return this->matrix[pair];
	}
	return 0;
}
	
void Matrix::setValue(int rowIndex, int colIndex, double value) {
	pair<int, int> pair = make_pair(rowIndex, colIndex);
	this->matrix[pair] = value;
}

list<Movie> Matrix::seenBy(User &user, map<int, Movie> &movies) {
	list<Movie> seen;

	for(map<int, Movie>::iterator it = movies.begin(); it != movies.end(); it++) {
		Movie movie = it->second;
		pair<int, int> pair = make_pair(user.getId(), movie.getId());
		if(this->matrix.find(pair) != this->matrix.end()) {
			seen.push_back(movie);
		}
	}

	return seen;
}
