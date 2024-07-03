#include "pch.h"
#include "../Project10/Baseball.cpp"
#include <string>
using namespace std;

TEST(BaseballGame, ThrowExceptionWhenWrongInputLength) {
	Game game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}