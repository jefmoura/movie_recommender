#pragma once
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class TFIDFDirectValue {
	
	private:
		int position;
		string term;
		int frequency;
	
	public:
		TFIDFDirectValue();
		int getPosition();
		void setPosition(int position);
		string getTerm();
		void setTerm(string term);
		int getFrequency();
		void setFrequency(int frequency);

};