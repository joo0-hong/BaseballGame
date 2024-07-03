#include "pch.h"
#include "../Project10/Baseball.cpp"
#include <string>
using namespace std;

class BaseballFixture : public testing::Test {
public :
	Game game{ "123" };
	void AssertIllegalArgument(string guessNum) {
		try {
			game.guess(guessNum);
			FAIL();
		}
		catch (exception e)
		{
			// pass
		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidParameter) {
	AssertIllegalArgument("12");
	AssertIllegalArgument("12s");
	AssertIllegalArgument("121");
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber) {
	guessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(result.strikes, 3);
	EXPECT_EQ(result.balls, 0);

}

TEST_F(BaseballFixture, ReturnSolvedResultIf2S0B) {
	guessResult result = game.guess("124");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(result.strikes, 2);
	EXPECT_EQ(result.balls, 0);

}
