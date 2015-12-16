#include "ParameterParser.hpp"

using namespace std;

void ParameterParser::contentParser(string movieFilePath, map<int, Movie> &movies) {
	ifstream reader(movieFilePath.c_str());
	string line;

    getline(reader, line);
	while(getline(reader, line)) {
		size_t pos = line.find("{");
		string itemId = line.substr(1, pos-1);
		string contentJson = line.substr(pos);

		if(itemId.size() > 0 && contentJson.size() > 0) {
			rapidjson::Document document;
			document.Parse(contentJson.c_str());

			Movie movie(atoi(itemId.c_str()));

            if(document.HasMember("Title"))
                movie.setTitle(document["Title"].GetString());
            if(document.HasMember("Year"))
                movie.setYear(document["Year"].GetString());
            if(document.HasMember("Genre"))
                movie.setGenres(document["Genre"].GetString());
            if(document.HasMember("Director"))
                movie.setDirector(document["Director"].GetString());
            if(document.HasMember("Actors"))
                movie.setActors(document["Actors"].GetString());
            if(document.HasMember("Plot"))
                movie.setPlot(document["Plot"].GetString());
            if(document.HasMember("Language"))
                movie.setLanguages(document["Language"].GetString());
            if(document.HasMember("Country"))
                movie.setCountries(document["Country"].GetString());
            if(document.HasMember("Awards"))
                movie.setAwards(document["Awards"].GetString());

			movies[atoi(itemId.c_str())] = movie;
		}
	}
	reader.close();
}
	
void ParameterParser::readRatingsFile(string filename, map<int, Movie> &movies, map<int,User> &users, list<Rating> &ratings) {
    ifstream data(filename.c_str());
    string line;
    getline(data, line);

    while(getline(data, line)){
        replace( line.begin(), line.end(), ':', ',' );

        stringstream lineStream(line);
        string cell;
        int countField = 0;
        int idMovie, idUser, rating;

        while(getline(lineStream, cell, ',')){
            
            

            if(countField == 0) {
                idUser = userClean(cell);
                User u(idUser);
                users[idUser] = u;
                countField++;
            }
            else if(countField == 1 )  {
                idMovie = movieClean(cell);
                Movie m(idMovie);
                movies[idMovie] = m;
                countField++;
            }
            else if(countField == 2 ){
                rating = atoi(cell.c_str());
                ratings.push_back( Rating( users[idUser], movies[idMovie], rating ) );
                countField++;
            } 
            else if (countField == 3){
            }
        }
    }
}

void ParameterParser::readTargetsFile(string filename, map<int, Movie> &movies, map<int,User> &users, list<Prediction> &predictions) {
    ifstream data(filename.c_str());
    string line;
    getline(data, line);

    while(getline(data, line)){
        stringstream lineStream(line);
        string cell;
        int countField = 0;

        int idUser, idMovie;

        while(getline(lineStream, cell, ':')){
            if(countField == 0){
                idUser = userClean(cell);
                countField++;
            }
            else {
                idMovie = movieClean(cell);
                countField++;
            }
        }
            Prediction pr(users[idUser], movies[idMovie], 0.0);
            predictions.push_back(pr);
    }
}
