#pragma once
#include <iostream>
#include <cstdio>
#include <fstream>
#include "User.hpp"
#include "Movie.hpp"

using namespace std;

class Prediction {

	private:
		User u;
		Movie m;
		double prediction;

	public:
		Prediction(User u, Movie m, double pred);
		User getUser();
		Movie getMovie();
		double getPrediction();
		void setPrediction(double prediction);
};

void savePrediction(list<Prediction> &predictions);