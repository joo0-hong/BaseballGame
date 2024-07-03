#include <iostream>
#include <string>
using namespace std;

struct guessResult {
public:
	bool solved;
	int strikes;
	int balls;
};

class Game {
public:
	const int MAX_LETTERS = 3;
	Game(const string& str) : question(str) {}
	guessResult guess(const string& guessNum) {
		guessResult result = { false,0,0 };
		AssertIllegalArgument(guessNum);
		if (guessNum == question)
			return { true, MAX_LETTERS, 0 };

		CountStrikes(guessNum, result);
		CountBalls(guessNum, result);

		return result;
	}

	void CountBalls(const std::string& guessNum, guessResult& result)
	{
		for (int i = 0; i < MAX_LETTERS; i++) {
			if (guessNum[i] == question[(i + 1) % MAX_LETTERS]
				|| guessNum[i] == question[(i + 2) % MAX_LETTERS])
				result.balls++;
		}
	}

	void CountStrikes(const std::string& guessNum, guessResult& result)
	{
		for (int i = 0; i < MAX_LETTERS; i++) {
			if (guessNum[i] == question[i]) result.strikes++;
		}
	}
	void AssertIllegalArgument(const std::string& guessNum)
	{
		if (guessNum.length() != MAX_LETTERS) {
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

private:
	string question;
};