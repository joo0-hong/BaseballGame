#include <iostream>
#include <string>
using namespace std;

struct guessResult {
	bool solved;
	int strikes;
	int balls;
};

class Game {
public : 
	Game(const string& str) : question(str) {}
	guessResult guess(const string& guessNum) {
		AssertIllegalArgument(guessNum);
		if(guessNum == question) return { true, 3, 0 };
		return { false,0,0 };
	}
	void AssertIllegalArgument(const std::string& guessNum)
	{
		if (guessNum.length() != 3) {
			throw length_error("Must be 3 letters");
		}

		for (char ch : guessNum) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be letter");
		}

		if (IsDuplicatedNum(guessNum)) {
			throw invalid_argument("Must not have the same letters");
		}
	}
	bool IsDuplicatedNum(const std::string& guessNum)
	{
		return guessNum[0] == guessNum[1]
			|| guessNum[1] == guessNum[2]
			|| guessNum[0] == guessNum[2];
	}

private :
	string question;
};