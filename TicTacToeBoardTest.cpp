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

// toggleTurn tests
TEST(TicTacToeBoardTest, toggleTurnOnce)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.toggleTurn(), O);
}

TEST(TicTacToeBoardTest, toggleTurnTwice)
{
	TicTacToeBoard board;
	board.toggleTurn();
	ASSERT_EQ(board.toggleTurn(), X);
}

TEST(TicTacToeBoardTest, toggleTurnThreeTimes)
{
	TicTacToeBoard board;
	board.toggleTurn();
	board.toggleTurn();
	ASSERT_EQ(board.toggleTurn(), O);
}

// placePiece tests
TEST(TicTacToeBoardTest, placePieceAt00)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(0, 0), X);
}

TEST(TicTacToeBoardTest, placePieceOutOfBound44)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(4, 4), Invalid);
}

// getPiece tests
TEST(TicTacToeBoardTest, getPieceAtBlank00)
{
	TicTacToeBoard board;
	board.getPiece(0, 0);
	ASSERT_EQ(board.toggleTurn(), Blank);
}

// getWinner tests
TEST(TicTacToeBoardTest, getWinnerEmptyBoard)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.getWinner(), Invalid);
}

TEST(TicTacToeBoardTest, getWinnerPartiallyEmptyBoard)
{
	TicTacToeBoard board;
	board.placePiece(0, 0);
	ASSERT_EQ(board.getWinner(), Invalid);
}

TEST(TicTacToeBoardTest, getWinnerXHorzontalWin)
{
	TicTacToeBoard board;
	board.placePiece(0, 0); // X
	board.placePiece(1, 0); // O
	board.placePiece(0, 1); // X
	board.placePiece(2, 0); // O
	board.placePiece(0, 2); // X
	ASSERT_EQ(board.getWinner(), Invalid);
}