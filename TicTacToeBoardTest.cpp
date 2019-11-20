/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"

class TicTacToeBoardTest : public ::testing::Test
{
protected:
	TicTacToeBoardTest() {}			 //constructor runs before each test
	virtual ~TicTacToeBoardTest() {} //destructor cleans up after tests
	virtual void SetUp() {}			 //sets up before each test (after constructor)
	virtual void TearDown() {}		 //clean up after each test, (before destructor)
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, toggleTurnOnce)
{
	ASSERT_EQ(toggleTurn(), O);
}

TEST(TicTacToeBoardTest, toggleTurnTwice)
{
	toggleTurn();
	ASSERT_EQ(toggleTurn(), X);
}