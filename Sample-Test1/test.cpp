#include "pch.h"
#include "../Project10/Baseball.cpp"
#include <string>
using namespace std;

class BaseballFixture : public testing::Test {
public : 
	Game game;
	void AssertIllegalArgument(string guessNum) {
		try {
			game.guess(guessNum);
		}
		catch (exception e)
		{
			// pass
		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidParameter) {
	Game game;
	AssertIllegalArgument("12");
	AssertIllegalArgument("12s");
}
