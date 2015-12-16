#pragma once
#include <iostream>
#include "User.hpp"
#include "Movie.hpp"

using namespace std;

class Rating {

	private:
		User user;
		Movie movie;
		double score;

	public:
		Rating();
		Rating(User &user, Movie &movie, double score);
		bool equals(Rating obj);
		User getUser();
		void setUser(User user);
		Movie getMovie();
		void setMovie(Movie movie);
		double getScore();
		void setScore(double score);
};
