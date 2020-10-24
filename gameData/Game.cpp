//
//Armada
//Game.cpp
//Created by Lo Evans.
//
#include "Game.h"
#include <iostream>

using namespace std;

//Constructors
Game::Game() 
	: player1sTurn(true), gameWon(false), gameLost(false)
	{ /* intentionally blank */ }

//Acessor functions

bool Game::getPlayer1sTurn() {
	return player1sTurn;
}

bool Game::getGameWon() {
	return gameWon;
}

bool Game::getGameLost() {
	return gameLost;
}

//Mutator functions
void Game::setPlayer1sTurn(bool turn) {
	player1sTurn = turn;
}

void Game::setGameWon(bool won) {
	gameWon = won;
}

void Game::setGameLost(bool lost) {
	gameLost = lost;
}

//Game function
void Game::playGame(Player* Player1, Player2* Computer, GameBoard* Player1Ships, GameBoard* Player1Shots, GameBoard* ComputerShips, GameBoard* ComputerShots, Ship* Player1Carrier, Ship* Player1Battleship, Ship* Player1Cruiser, Ship* Player1Submarine, Ship* Player1Destroyer, Ship* ComputerCarrier, Ship* ComputerBattleship, Ship* ComputerCruiser, Ship* ComputerSubmarine, Ship* ComputerDestroyer) {
		while(true) {
		if (this -> getPlayer1sTurn()) {
			Player1 -> fireTorpedo(ComputerShips, Player1Shots, ComputerCarrier, ComputerBattleship, ComputerCruiser, ComputerSubmarine, ComputerDestroyer);
			Player1 -> checkShip(ComputerCarrier);
			Player1 -> checkShip(ComputerBattleship);
			Player1 -> checkShip(ComputerCruiser);
			Player1 -> checkShip(ComputerSubmarine);
			Player1 -> checkShip(ComputerDestroyer);
			this -> setPlayer1sTurn(false);
		} else {
			Computer -> fireTorpedo(Player1Ships, ComputerShots, Player1Carrier, Player1Battleship, Player1Cruiser, Player1Submarine, Player1Destroyer);
			Computer -> checkShip(Player1Carrier);
			Computer -> checkShip(Player1Battleship);
			Computer -> checkShip(Player1Cruiser);
			Computer -> checkShip(Player1Submarine);
			Computer -> checkShip(Player1Destroyer);
			Player1Ships -> printBoard();
			this -> setPlayer1sTurn(true);
		}

		if (Computer -> getShipCount() == 0) {
			this -> setGameWon(true);
			break;
		}

		if (Player1 -> getShipCount() == 0) {
			this -> setGameLost(true);
			break;
		}
	}

	if (this -> getGameWon()) {
		cout << "You Win!\n";

		}
	if (this -> getGameLost()) {
		cout << "You lose!\n";
		}

}