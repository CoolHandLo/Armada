//
//Armada
//Game.cpp
//Created by Lo Evans.
//
#include "Game.h"

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
void Game::playGame() {
	
}