#pragma once
#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

class User {

	private:
		int id;
		double average;

	public:
		User();
		User(int id);
		int getId();
		void setId(int id);
};

int userClean(string userIdStr);