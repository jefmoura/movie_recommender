#pragma once
#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

class Movie {
	
	private:
		int id;
		string title;
		string year;
		string genres;
		string director;
		string actors;
		string plot;
		string languages;
		string countries;
		string awards;

	public:
		Movie();
		Movie(int id);
		bool equals(Movie obj);
		list<string> split(string str);
		list<string> serialize();
		int getId();
		void setId(int id);
		void setTitle(string title);
		void setYear(string year);
		void setGenres(string genres);
		void setDirector(string director);
		void setActors(string actors);
		void setPlot(string plot);
		void setLanguages(string language);
		void setCountries(string countries);
		void setAwards(string awards);
};

int movieClean(string movieIdStr);