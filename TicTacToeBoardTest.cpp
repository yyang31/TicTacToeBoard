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
TEST(TicTacToeBoardTest, placePieceOutOfBound44)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(4, 4), Invalid);
}

TEST(TicTacToeBoardTest, placePieceOutOfBoundNeg1Neg1)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(-1, -1), Invalid);
}

TEST(TicTacToeBoardTest, placePieceOutOfBound05)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(0, 5), Invalid);
}

TEST(TicTacToeBoardTest, placePieceOutOfBoundNeg12)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(-1, 2), Invalid);
}

TEST(TicTacToeBoardTest, placePieceOutOfBound62)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(6, 2), Invalid);
}

TEST(TicTacToeBoardTest, placePieceOnExsitingLocation01)
{
	TicTacToeBoard board;
	board.placePiece(0, 1);
	ASSERT_EQ(board.placePiece(0, 1), X);
}

TEST(TicTacToeBoardTest, placePieceOnExsitingLocation21)
{
	TicTacToeBoard board;
	board.placePiece(0, 1);
	board.placePiece(2, 1);
	board.placePiece(0, 2);
	ASSERT_EQ(board.placePiece(2, 1), O);
}

TEST(TicTacToeBoardTest, placePieceAt00)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(0, 0), X);
}

TEST(TicTacToeBoardTest, placePieceAt21)
{
	TicTacToeBoard board;
	board.placePiece(0, 1);
	board.placePiece(1, 1);
	board.placePiece(0, 2);
	board.placePiece(2, 0);
	ASSERT_EQ(board.placePiece(2, 1), X);
}

// getPiece tests
TEST(TicTacToeBoardTest, getPieceAtOutOfBoundNeg1Neg1)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.getPiece(-1, -1), Invalid);
}

TEST(TicTacToeBoardTest, getPieceAtOutOfBoundNeg12)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.getPiece(-1, 2), Invalid);
}

TEST(TicTacToeBoardTest, getPieceAtOutOfBound33)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.getPiece(3, 3), Invalid);
}

TEST(TicTacToeBoardTest, getPieceAtOutOfBound05)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.getPiece(0, 5), Invalid);
}

TEST(TicTacToeBoardTest, getPieceAtBlank00)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.getPiece(0, 0), Blank);
}

TEST(TicTacToeBoardTest, getPieceAtExisting11)
{
	TicTacToeBoard board;
	board.placePiece(1, 1);
	ASSERT_EQ(board.getPiece(0, 0), X);
}

TEST(TicTacToeBoardTest, getPieceAtExisting00)
{
	TicTacToeBoard board;
	board.placePiece(0, 1);
	board.placePiece(0, 0);
	board.placePiece(1, 1);
	ASSERT_EQ(board.getPiece(0, 0), O);
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
	ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoardTest, getWinnerOVerticalWin)
{
	TicTacToeBoard board;
	board.placePiece(2, 2); // X
	board.placePiece(0, 0); // O
	board.placePiece(1, 2); // X
	board.placePiece(1, 0); // O
	board.placePiece(1, 1); // X
	board.placePiece(2, 0); // O
	ASSERT_EQ(board.getWinner(), O);
}

TEST(TicTacToeBoardTest, getWinnerODiagonalWin)
{
	TicTacToeBoard board;
	board.placePiece(0, 2); // X
	board.placePiece(0, 0); // O
	board.placePiece(1, 2); // X
	board.placePiece(1, 1); // O
	board.placePiece(0, 1); // X
	board.placePiece(2, 2); // O
	ASSERT_EQ(board.getWinner(), O);
}

TEST(TicTacToeBoardTest, getWinnerNoWinner)
{
	TicTacToeBoard board;
	board.placePiece(0, 0); // X
	board.placePiece(1, 0); // O
	board.placePiece(1, 1); // X
	board.placePiece(2, 2); // O
	board.placePiece(2, 0); // X
	board.placePiece(0, 2); // O
	board.placePiece(1, 2); // X
	board.placePiece(0, 1); // O
	board.placePiece(2, 1); // X
	ASSERT_EQ(board.getWinner(), Blank);
}