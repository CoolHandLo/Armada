//
//Armada
//Game.h
//Created by Lo Evans.
//
#ifndef Game_h
#define Game_h
#include "Player2.h"

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
		void playGame(Player* Player1, Player2* Computer, GameBoard* Player1Ships, GameBoard* Player1Shots, GameBoard* ComputerShips, GameBoard* ComputerShots, Ship* Player1Carrier, Ship* Player1Battleship, Ship* Player1Cruiser, Ship* Player1Submarine, Ship* Player1Destroyer, Ship* ComputerCarrier, Ship* ComputerBattleship, Ship* ComputerCruiser, Ship* ComputerSubmarine, Ship* ComputerDestroyer);
};

#endif /* Game_h */