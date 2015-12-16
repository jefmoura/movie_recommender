#include "Movie.hpp"
#include <cstring>

using namespace std;

Movie::Movie() {}

Movie::Movie(int id) {
	this->id = id;
}

bool Movie::equals(Movie obj) {
	if (this->id == obj.getId()) {
		return true;
	}
	return false;
}

list<string> Movie::split(string str) {
	list<string> internal;
	stringstream ss(str); // Turn the string into a stream.
	string tok;
  
	while(getline(ss, tok, ' ')) {
		if(tok.size() > 2)
			internal.push_back(tok);
	}
  
	return internal;
}
	
list<string> Movie::serialize() {
	list<string> content;
	
	if(this->year.size() > 0) {
		content.push_back(this->year);
	}
	if(this->title.size() > 0) {
		content.push_back(this->title);
	}
	if(this->genres.size() > 0) {
		content.push_back(this->genres);
	}
	if(this->director.size() > 0) {
		content.push_back(this->director);
	}
	//if(this->actors.size() > 0) {
	//	content.push_back(this->actors);
	//}
	if(this->languages.size() > 0) {
		content.push_back(this->languages);
	}
	if(this->countries.size() > 0) {
		content.push_back(this->countries);
	}
	//if(this->awards.size() > 0) {
	//	content.push_back(this->awards);
	//}

	if(this->actors.size() > 0) {
	 	char* dup = strdup(actors.c_str());
	 	char* token = strtok(dup, " ,");
	 	while(token != NULL){
	 		content.push_back(string(token));
	 		token = strtok(NULL, " ,");
	 	}
	 	free(dup);
	}
	if(this->awards.size() > 0) {
	 	char* dup = strdup(awards.c_str());
	 	char* token = strtok(dup, " ,");
	 	while(token != NULL){
	 		content.push_back(string(token));
	 		token = strtok(NULL, " ,");
	 	}
	 	free(dup);
	}
	if(this->plot.size() > 0) {
	 	char* dup = strdup(plot.c_str());
	 	char* token = strtok(dup, " ,.");
	 	while(token != NULL){
	 		content.push_back(string(token));
	 		token = strtok(NULL, " ,.");
	 	}
	 	free(dup);
	}
	
	return content;
}

int movieClean(string movieIdStr) {
	return atoi(movieIdStr.substr(1,movieIdStr.size()-1).c_str());
}

int Movie::getId() {
	return id;
}
	
void Movie::setId(int id) {
	this->id = id;
}

void Movie::setTitle(string title){
	this->title = title;
}

void Movie::setYear(string year){
	this->year = year;
}

void Movie::setGenres(string genres){
	this->genres = genres;
}

void Movie::setDirector(string director){
	this->director = director;
}

void Movie::setActors(string actors){
	this->actors = actors;
}

void Movie::setPlot(string plot){
	this->plot = plot;
}

void Movie::setLanguages(string language){
	this->languages = language;
}

void Movie::setCountries(string countries){
	this->countries = countries;
}

void Movie::setAwards(string awards){
	this->awards = awards;
}
