#pragma once
#include <iostream>
#include <cstdlib>
#include <list>
#include <iterator>
#include <string>
#include <cmath>
#include <map>

#include "Movie.hpp"
#include "Prediction.hpp"
#include "Rating.hpp"
#include "User.hpp"

using namespace std;

class Matrix {

	private:
		map<pair<int, int>, double> matrix;
		int rowSize;
		int columnSize;

	public:
		Matrix();
		Matrix(list<Rating> &ratings);
		double rating(User &user, Movie &movie);
		double rating(int termIndex, User user);
		void setValue(int rowIndex, int colIndex, double value);
		list<Movie> seenBy(User &user, map<int,Movie> &movies);
};