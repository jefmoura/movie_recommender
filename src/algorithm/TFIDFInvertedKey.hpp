#pragma once
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class TFIDFInvertedKey {
	private:
		string term;
		int itemNumber;
	
	
	public:
		TFIDFInvertedKey();
		string getTerm();
		void setTerm(string term);
		int getItemNumber();
		void setItemNumber(int itemNumber);
		bool operator <(const TFIDFInvertedKey& rhs) const {
			return (itemNumber < rhs.itemNumber);
		};
};
