#include "User.hpp"

using namespace std;

User::User() {}

User::User(int id) {
	this->id = id;
	this->average = 0.0;
}

int User::getId() {
	return id;
}
	
void User::setId(int id) {
	this->id = id;
}

int userClean(string userIdStr) {
	return atoi(userIdStr.substr(1,userIdStr.size()-1).c_str());
}
