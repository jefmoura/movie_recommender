#pragma once
#include <iostream>
#include <list>
#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

#include "../model/Movie.hpp"
#include "../model/Rating.hpp"
#include "../model/User.hpp"
#include "../model/Prediction.hpp"
#include "../rapidjson/document.h"

class ParameterParser {

	public:
		static void contentParser(string movieFilePath, map<int, Movie> &movies);
		static void readRatingsFile(string filename, map<int, Movie> &movies, map<int,User> &users, list<Rating> &ratings);
		static void readTargetsFile(string filename, map<int, Movie> &movies, map<int,User> &users, list<Prediction> &predictions);

};