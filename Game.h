//
//Armada
//Game.h
//Created by Lo Evans.
//
#ifndef Game_h
#define Game_h

class Game {
	private:
		bool player1sTurn;
		bool gameWon;
		bool gameLost;

	public:
		//Constustor
		Game();
	
		//Asseccor functions
		bool getPlayer1sTurn();
		bool getGameWon();
		bool getGameLost();

		//Mutator functions
		void setPlayer1sTurn(bool turn);
		void setGameWon(bool won);
		void setGameLost(bool lost);

		//Game function
		void playGame();
};

#endif /* Game_h */