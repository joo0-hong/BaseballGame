#include <iostream>
#include <string>
using namespace std;

class Game {
public : 
	void guess(const string& guessNum) {
		if (guessNum.length() != 3){
			throw length_error("Must be 3 letters");
		}

		for (char ch : guessNum) {
			if (ch < '0' || ch > '9')
				throw invalid_argument("Must be letter");
		}
	}
};