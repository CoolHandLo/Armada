//
//Armada
//GameBoard.h
//Created by Lo Evans
//
#ifndef GameBoard_h
#define GameBoard_h


class GameBoard {

	public:

		//Default constructor
		GameBoard();
	
		//Creates a board ready 
		//for a new game.
		void cleanBoard();

		//Prints board to screen.
		void printBoard();

		//Accessor functions 
		int getBoardWidth();
		int getBoardHeight();
		char getChar(int xVal, int yVal);

		//Mutator function
		void setChar(char val, int xVal, int yVal);

	private:
	
		static const int boardWidth  = 10;
		static const int boardHeight  = 10;
		char board[boardWidth][boardHeight];

};


#endif /* GameBoard_h */