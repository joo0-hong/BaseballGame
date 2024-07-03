#include <iostream>
#include <string>
using namespace std;

class Game {
public : 
	void guess(const string& str) {
		if (str.length() != 3)
			throw length_error("Must be 3 letters");
	}
};