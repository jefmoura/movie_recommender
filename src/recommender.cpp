#include <algorithm>
#include <cmath>

#include "model/Matrix.hpp"
#include "model/Movie.hpp"
#include "model/Prediction.hpp"
#include "model/Rating.hpp"
#include "model/User.hpp"
#include "parser/ParameterParser.hpp"
#include "algorithm/TFIDFInvertedIndex.hpp"
#include "algorithm/TFIDFInvertedKey.hpp"
#include "algorithm/TFIDFDirectIndex.hpp"

using namespace std;

int main(int argc, char** argv){
	map<int, Movie> movies;
	map<int, User> users;
	list<Rating> ratings;
	list<Prediction> predictions;
	TFIDFInvertedIndex invertedIndex;
	TFIDFDirectIndex directIndex;

	ParameterParser::contentParser(argv[1], movies);
	ParameterParser::readRatingsFile(argv[2], movies, users, ratings);
	ParameterParser::readTargetsFile(argv[3], movies, users, predictions);

	for(map<int,Movie>::iterator it_movie = movies.begin(); it_movie != movies.end(); it_movie++) {
		Movie movie = it_movie->second;
		list<string> terms = movie.serialize();
		for(list<string>::iterator term = terms.begin(); term != terms.end(); term++) {
			if(term->size() > 2){
				TFIDFInvertedKey key = invertedIndex.addElement(*term, movie, 1);
				directIndex.addElement(movie, key, 1);
			}
		}
	}

	Matrix utilityMatrix (ratings);
	Matrix userTermMatrix;
			
	double result = 0;

	for(map<int,User>::iterator it_user = users.begin(); it_user != users.end(); it_user++) {
		User user = it_user->second;
		list<Movie> seenBy = utilityMatrix.seenBy(user, movies);
		list<TFIDFInvertedKey> keys = invertedIndex.keys();
		for(list<TFIDFInvertedKey>::iterator key = keys.begin(); key != keys.end(); key++) {
			list<TFIDFInvertedValue> values = invertedIndex.getValues(key->getTerm());
			double amount = 0;
			int count = 0;
			for(list<Movie>::iterator movie = seenBy.begin(); movie != seenBy.end(); movie++) {
				double utilityValue = utilityMatrix.rating(user, *movie);
				double termValue = frequencyBy(values, movie->getId() - 1);
				if (utilityValue != 0 && termValue != 0) {
					count++;
					amount += utilityValue * termValue;
				}
			}
			if (count != 0) {
				result = amount / count;
			} else {
				result = 0;
			}
			userTermMatrix.setValue(key->getItemNumber(), user.getId() - 1, result);
		}
	}
	
	for(list<Prediction>::iterator prediction = predictions.begin(); prediction != predictions.end(); prediction++) {
		double up = 0;
		double downA = 0;
		double downB = 0;
		list<TFIDFDirectValue> values = directIndex.getValues(prediction->getMovie());
		for(list<TFIDFDirectValue>::iterator value = values.begin(); value != values.end(); value++) {
			double invertedValue = value->getFrequency();
			double userTermValue = userTermMatrix.rating(value->getPosition(), prediction->getUser());
			up += invertedValue * userTermValue;
			downA += pow(invertedValue, 2);
			downB += pow(userTermValue, 2);
		}
		if(downA != 0 && downB != 0) {
			downA = sqrt(downA);
			downB = sqrt(downB);
			result = (up / (downA * downB));
		} else {
			result = 0;
		}
		prediction->setPrediction(5 * result);
	}

	savePrediction(predictions);

	return 0;
}